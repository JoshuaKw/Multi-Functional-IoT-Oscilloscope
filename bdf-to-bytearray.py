import string

# CHAR_MAP = {'space': ' ',
#             'one':'1',
#             'two':'2',
#             'three':'3',
#             ''}
alphabet = list(string.ascii_letters)
WIDTH = 5
HEIGHT = 8

def read_BDF(file_name, wanted_chars):
    font = {}
    with open(file_name, 'r') as bdf:
        stack = []
        line = bdf.readline()
        while line:
            words = [word.strip() for word in line.split(' ')]
            if words[0] == 'STARTCHAR':
                char = words[1]
                if char in wanted_chars:
                    char_line = bdf.readline()
                    bdf_char = []
                    while not char_line.strip() == 'ENDCHAR':
                        bdf_char.append(char_line)
                        char_line = bdf.readline()
                    font[char] = read_char(char, bdf_char)
            line = bdf.readline()
    return font

def read_char(char, char_lines):
    char_lines_iter = iter(char_lines)
    line = char_lines_iter.next()
    binary_plot = []
    while line:
        try:
            words = [word.strip() for word in line.split(' ')]
            if words[0] == 'BITMAP':
                hex_strings = []
                for i in range(HEIGHT):
                    hex_strings.append(char_lines_iter.next())
                hex_strings = [byte.strip() for byte in hex_strings]
                binary_plot = ['0b{0:05b}'.format(int(hex_string, 16) >> 3) for hex_string in hex_strings]
                # binary_plot = ['{0:05b}'.format(int(hex_string, 16) >> 3).replace('0', ' ') for hex_string in hex_strings]
                # binary_plot = [bin(int(hex_string, 16) >> 3) for hex_string in hex_strings]
                # print char, binary_plot
                # print_letter(binary_plot)
            line = char_lines_iter.next()
        except StopIteration:
            break
    return binary_plot

def print_letter(binary_slices):
    for slice in binary_slices:
        print slice
    print

def write_array(path, font):
    ascii_array = []
    for i in xrange(128):
        ascii_array.append([])
    for letter, data in font.items():
        ascii_array[ord(letter)] = data

    with open(path, 'w') as outfile:
        outfile.write('const font[128][8] = {\n')
        for letter in ascii_array:
            outfile.write('\t{')
            outfile.write(','.join(letter))
            outfile.write('},\n')
        outfile.write('};')

font = read_BDF('5x8.bdf', alphabet)
write_array('out.cpp', font)

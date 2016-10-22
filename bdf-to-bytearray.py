import string

def create_char_map(file_name):
    mapping = {}
    with open(file_name, 'r') as glyphlist:
        for line in glyphlist:
            words = [word.strip() for word in line.split(';')]
            abbreviation = words[0]
            if len(words[1].split(' ')) is 1:
                uni = words[1]
                character = unichr(int(uni, 16)).encode('ascii', 'ignore')
                mapping[abbreviation] = character
    ascii_mapping = {}
    for (abbr, char) in mapping.items():
        if not char == '':
            ascii_mapping[abbr] = char
    return ascii_mapping

char_map = create_char_map('glyphlist.txt')
# print char_map['one']

# alphabet = list(string.ascii_letters)
all_ascii = list(string.printable)
WIDTH = 5
HEIGHT = 8

def read_BDF(file_name, wanted_chars):
    font = {}
    with open(file_name, 'r') as bdf:
        stack = []
        line = bdf.readline()
        while line:
            words = [word.strip() for word in line.split(' ')]
            if words[0] == 'STARTCHAR' and words[1] in char_map.keys():
                char = char_map[words[1]]
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
                # flip over x and y axis because of how drawing works
                binary_plot = list(reversed(['0b'+('{0:05b}'.format(int(hex_string, 16) >> 3)[::-1]) for hex_string in hex_strings]))
                # binary_plot = list(reversed([('{0:05b}'.format(int(hex_string, 16) >> 3)[::-1]).replace('0', ' ') for hex_string in hex_strings]))
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

# font = read_BDF('5x8.bdf', alphabet)
font = read_BDF('5x8.bdf', all_ascii)
write_array('lib/out/out.cpp', font)

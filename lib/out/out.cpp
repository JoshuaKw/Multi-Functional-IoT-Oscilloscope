const font[128][8] = {
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{},
	{0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000},
	{0b00000,0b00100,0b00000,0b00100,0b00100,0b00100,0b00100,0b00000},
	{0b00000,0b00000,0b00000,0b00000,0b01010,0b01010,0b01010,0b00000},
	{0b00000,0b01010,0b01010,0b11111,0b01010,0b11111,0b01010,0b01010},
	{0b00000,0b00100,0b01110,0b10100,0b01110,0b00101,0b01110,0b00100},
	{0b00000,0b00000,0b01000,0b01010,0b00100,0b01010,0b00010,0b00000},
	{0b00000,0b01010,0b00101,0b00101,0b00010,0b00101,0b00101,0b00010},
	{0b00000,0b00000,0b00000,0b00000,0b00100,0b00100,0b00100,0b00000},
	{0b00000,0b00100,0b00010,0b00010,0b00010,0b00010,0b00100,0b00000},
	{0b00000,0b00010,0b00100,0b00100,0b00100,0b00100,0b00010,0b00000},
	{0b00000,0b01001,0b00110,0b01111,0b00110,0b01001,0b00000,0b00000},
	{0b00000,0b00100,0b00100,0b11111,0b00100,0b00100,0b00000,0b00000},
	{0b00010,0b00100,0b01100,0b00000,0b00000,0b00000,0b00000,0b00000},
	{0b00000,0b00000,0b00000,0b01110,0b00000,0b00000,0b00000,0b00000},
	{0b00100,0b01110,0b00100,0b00000,0b00000,0b00000,0b00000,0b00000},
	{0b00000,0b00001,0b00001,0b00010,0b00100,0b01000,0b01000,0b00000},
	{0b00000,0b00100,0b01010,0b01010,0b01010,0b01010,0b00100,0b00000},
	{0b00000,0b01110,0b00100,0b00100,0b00100,0b00110,0b00100,0b00000},
	{0b00000,0b01111,0b00001,0b00110,0b01000,0b01001,0b00110,0b00000},
	{0b00000,0b00110,0b01001,0b01000,0b00110,0b00100,0b01111,0b00000},
	{0b00000,0b00100,0b00100,0b01111,0b00101,0b00110,0b00100,0b00000},
	{0b00000,0b00110,0b01001,0b01000,0b00111,0b00001,0b01111,0b00000},
	{0b00000,0b00110,0b01001,0b01001,0b00111,0b00001,0b00110,0b00000},
	{0b00000,0b00010,0b00010,0b00100,0b00100,0b01000,0b01111,0b00000},
	{0b00000,0b00110,0b01001,0b01001,0b00110,0b01001,0b00110,0b00000},
	{0b00000,0b00110,0b01000,0b01110,0b01001,0b01001,0b00110,0b00000},
	{0b00000,0b00110,0b00110,0b00000,0b00110,0b00110,0b00000,0b00000},
	{0b00010,0b00100,0b01100,0b00000,0b01100,0b01100,0b00000,0b00000},
	{0b00000,0b01000,0b00100,0b00010,0b00010,0b00100,0b01000,0b00000},
	{0b00000,0b00000,0b01111,0b00000,0b01111,0b00000,0b00000,0b00000},
	{0b00000,0b00010,0b00100,0b01000,0b01000,0b00100,0b00010,0b00000},
	{0b00000,0b00100,0b00000,0b00100,0b01000,0b01010,0b00100,0b00000},
	{0b01100,0b00010,0b01001,0b10101,0b10101,0b11001,0b10010,0b01100},
	{0b00000,0b01001,0b01001,0b01111,0b01001,0b01001,0b00110,0b00000},
	{0b00000,0b00111,0b01001,0b01001,0b00111,0b01001,0b00111,0b00000},
	{0b00000,0b00110,0b01001,0b00001,0b00001,0b01001,0b00110,0b00000},
	{0b00000,0b00111,0b01001,0b01001,0b01001,0b01001,0b00111,0b00000},
	{0b00000,0b01111,0b00001,0b00001,0b00111,0b00001,0b01111,0b00000},
	{0b00000,0b00001,0b00001,0b00001,0b00111,0b00001,0b01111,0b00000},
	{0b00000,0b00110,0b01001,0b01101,0b00001,0b01001,0b00110,0b00000},
	{0b00000,0b01001,0b01001,0b01001,0b01111,0b01001,0b01001,0b00000},
	{0b00000,0b01110,0b00100,0b00100,0b00100,0b00100,0b01110,0b00000},
	{0b00000,0b00010,0b00101,0b00100,0b00100,0b00100,0b01110,0b00000},
	{0b00000,0b01001,0b00101,0b00101,0b00011,0b00101,0b01001,0b00000},
	{0b00000,0b01111,0b00001,0b00001,0b00001,0b00001,0b00001,0b00000},
	{0b00000,0b01001,0b01001,0b01001,0b01111,0b01111,0b01001,0b00000},
	{0b00000,0b01001,0b01101,0b01101,0b01111,0b01011,0b01001,0b00000},
	{0b00000,0b00110,0b01001,0b01001,0b01001,0b01001,0b00110,0b00000},
	{0b00000,0b00001,0b00001,0b00111,0b01001,0b01001,0b00111,0b00000},
	{0b01000,0b00110,0b01101,0b01011,0b01001,0b01001,0b00110,0b00000},
	{0b00000,0b01001,0b01001,0b00111,0b01001,0b01001,0b00111,0b00000},
	{0b00000,0b00110,0b01001,0b00100,0b00010,0b01001,0b00110,0b00000},
	{0b00000,0b00100,0b00100,0b00100,0b00100,0b00100,0b01110,0b00000},
	{0b00000,0b00110,0b01001,0b01001,0b01001,0b01001,0b01001,0b00000},
	{0b00000,0b00110,0b00110,0b01001,0b01001,0b01001,0b01001,0b00000},
	{0b00000,0b01001,0b01111,0b01111,0b01001,0b01001,0b01001,0b00000},
	{0b00000,0b01001,0b01001,0b00110,0b00110,0b01001,0b01001,0b00000},
	{0b00000,0b00100,0b00100,0b00100,0b01010,0b10001,0b10001,0b00000},
	{0b00000,0b01111,0b00001,0b00010,0b00100,0b01000,0b01111,0b00000},
	{0b00000,0b01110,0b00010,0b00010,0b00010,0b00010,0b01110,0b00000},
	{0b00000,0b01000,0b01000,0b00100,0b00010,0b00001,0b00001,0b00000},
	{0b00000,0b01110,0b01000,0b01000,0b01000,0b01000,0b01110,0b00000},
	{0b00000,0b00000,0b00000,0b00000,0b00000,0b01010,0b00100,0b00000},
	{0b01111,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000},
	{0b00000,0b00000,0b00000,0b00000,0b00000,0b00100,0b00010,0b00000},
	{0b00000,0b01110,0b01001,0b01001,0b01110,0b00000,0b00000,0b00000},
	{0b00000,0b00111,0b01001,0b01001,0b00111,0b00001,0b00001,0b00000},
	{0b00000,0b01100,0b00010,0b00010,0b01100,0b00000,0b00000,0b00000},
	{0b00000,0b01110,0b01001,0b01001,0b01110,0b01000,0b01000,0b00000},
	{0b00000,0b00110,0b00011,0b01101,0b00110,0b00000,0b00000,0b00000},
	{0b00000,0b00010,0b00010,0b00111,0b00010,0b01010,0b00100,0b00000},
	{0b00110,0b01000,0b01110,0b01001,0b00110,0b00000,0b00000,0b00000},
	{0b00000,0b01001,0b01001,0b01001,0b00111,0b00001,0b00001,0b00000},
	{0b00000,0b01110,0b00100,0b00100,0b00110,0b00000,0b00100,0b00000},
	{0b00100,0b01010,0b01000,0b01000,0b01000,0b00000,0b01000,0b00000},
	{0b00000,0b01001,0b01001,0b00111,0b01001,0b00001,0b00001,0b00000},
	{0b00000,0b01110,0b00100,0b00100,0b00100,0b00100,0b00110,0b00000},
	{0b00000,0b10101,0b10101,0b10101,0b01011,0b00000,0b00000,0b00000},
	{0b00000,0b01001,0b01001,0b01001,0b00111,0b00000,0b00000,0b00000},
	{0b00000,0b00110,0b01001,0b01001,0b00110,0b00000,0b00000,0b00000},
	{0b00001,0b00001,0b00111,0b01001,0b00111,0b00000,0b00000,0b00000},
	{0b01000,0b01000,0b01110,0b01001,0b01110,0b00000,0b00000,0b00000},
	{0b00000,0b00001,0b00001,0b01011,0b00101,0b00000,0b00000,0b00000},
	{0b00000,0b00110,0b01000,0b00110,0b01100,0b00000,0b00000,0b00000},
	{0b00000,0b00100,0b01010,0b00010,0b00111,0b00010,0b00010,0b00000},
	{0b00000,0b01110,0b01001,0b01001,0b01001,0b00000,0b00000,0b00000},
	{0b00000,0b00100,0b01010,0b01010,0b01010,0b00000,0b00000,0b00000},
	{0b00000,0b01010,0b10101,0b10101,0b10001,0b00000,0b00000,0b00000},
	{0b00000,0b01001,0b00110,0b00110,0b01001,0b00000,0b00000,0b00000},
	{0b00110,0b01001,0b01110,0b01001,0b01001,0b00000,0b00000,0b00000},
	{0b00000,0b01111,0b00010,0b00100,0b01111,0b00000,0b00000,0b00000},
	{0b00000,0b01100,0b00010,0b00100,0b00011,0b00100,0b00010,0b01100},
	{0b00000,0b00100,0b00100,0b00100,0b00100,0b00100,0b00100,0b00000},
	{0b00000,0b00011,0b00100,0b00010,0b01100,0b00010,0b00100,0b00011},
	{0b00000,0b00000,0b00000,0b00000,0b00000,0b00101,0b01010,0b00000},
	{},
};
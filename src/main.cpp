#include "Arduino.h"
int column = 0;
#define maxColumns 5
int row = 0;
#define maxRows 8
#define rowIncrement 50
#define columnIncrement 40

char character[5] = {B11111110, B00001000, B00010000, B00010000, B00011110};

void setup(){

	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	analogWriteResolution(12);

}

void loop(){
	for(int x = 0; x < maxRows; x++){
		for(int y = 0; y < maxColumns; y++){
			if((character[y] >> x) & 1 != 0){
				analogWrite(A22, x*rowIncrement);
				analogWrite(A21, y*columnIncrement);
				delayMicroseconds(10);
			}
		}
	}
}

#include "Arduino.h"
#include "out.cpp"

int column = 0;
#define maxColumns 5
int row = 0;
#define maxRows 8
#define rowIncrement 40
#define columnIncrement 30
#define numCharacters 11
#define lineBufferSize 50

struct line {
	line* next;
	line* prev;
	char* lineContents;
	line(line* nextLine, line* prevLine) :
			next(nextLine), prev(prevLine), lineContents(nullptr) {}
};

void setupIO();
void setupLineBuffer(line** head, line** tail);

char display[27][27] = {
		 "            ",
	     "            ",
		 "    W  W    ",
		 "    W  W    ",
		 "            ",
		 " W        W ",
		 "  WWWWWWWW  ",
		 "            ",
};

void setup(){
	setupIO();
	

	line* lineBufferHead;
	line* lineBufferTail;
	setupLineBuffer(&lineBufferHead, &lineBufferTail);

	while (true) {
		for (int lineSelect = 0; lineSelect < 15; lineSelect++) {
			for (int charSelect = 0; charSelect < strlen(display[0]);
					charSelect++) {
				for (int y = 0; y < maxRows; y++) {
					for (int x = 0; x < maxColumns; x++) {
						if (((font[display[14 - lineSelect][charSelect]][y] >> x)
								& 1) != 0) {
							analogWrite(A21,x * columnIncrement + charSelect * 157);
							analogWrite(A22,y * rowIncrement + lineSelect * 280);
							delayMicroseconds(10);
						}
					}
				}
			}
		}
	}
}

void loop(){}

void setupIO() {
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	analogWriteResolution(12);
}

void setupLineBuffer(line** head, line** tail){
	*head = new line(nullptr, nullptr);
	line* tempOld = *head;
	for(int i = 1; i < lineBufferSize; i++){
		line* temp = new line(nullptr, tempOld);
		tempOld->next = temp;
		tempOld = temp;
	}
	*tail = tempOld;
}

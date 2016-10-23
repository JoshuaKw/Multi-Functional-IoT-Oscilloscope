#include "Arduino.h"
#include "out.cpp"

#define maxColumns 5
#define maxRows 8

#define rowIncrement 40
#define columnIncrement 30

#define lineBufferSize 50

#define numColumns 26
#define numRows 15

#define charDimX 5
#define charDimY 8

#define charSepX 157
#define charSepY 275

#define potPin A16

int frameCount = 0;
int frameRate = 512;
bool frameUp = false;
int frameUpCount = 0;

struct line {
	line* next;
	line* prev;
	char lineContents[26] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	line(line* nextLine, line* prevLine) :
			next(nextLine), prev(prevLine) {
	}
};

void setupLineBuffer(line** head, line** tail);
void lineBufferNewLine(line** head, line** tail, int &lineIndex);
bool lineNewCharacter(line** head, line** tail, int &lineIndex);
void writeCharacter(char letter, int x, int y);
void writeLine(char* letters, int y);
void writeToScreen(line** head);
void setupIO();

int main() {
	setupIO();
	line* lineBufferHead = nullptr;
	line* lineBufferTail = nullptr;
	int lineCharacterIndex = 0;
	setupLineBuffer(&lineBufferHead, &lineBufferTail);


	while (true) {
		while (lineNewCharacter(&lineBufferHead, &lineBufferTail, lineCharacterIndex));
		if(digitalRead(16) == 0){
			frameRate = analogRead(A16);
		}
		if (Serial.available()) {
			Serial1.write(Serial.read());
		}
		writeToScreen(&lineBufferHead);
	}
	return 0;
}

void setupLineBuffer(line** head, line** tail) {
	*head = new line(nullptr, nullptr);
	line* tempOld = *head;
	for (int i = 1; i < lineBufferSize; i++) {
		line* temp = new line(nullptr, tempOld);
		tempOld->next = temp;
		tempOld = temp;
	}
	*tail = tempOld;
}

void lineBufferNewLine(line** head, line** tail, int &lineIndex) {
	for (int charPos = 0; charPos < numColumns; charPos++) {
		(*tail)->lineContents[charPos] = ' ';
	}

	lineIndex = 0;
	//Link head and tail
	(*head)->prev = *tail;
	(*tail)->next = *head;

	//Shift head and tail pointers up
	*tail = (*tail)->prev;
	*head = (*head)->prev;

	//disconnect new head and tail
	(*tail)->next = nullptr;
	(*head)->prev = nullptr;
}

bool lineNewCharacter(line** head, line** tail, int &lineIndex) {
	int character;
	character = Serial1.read();
	if (character >= 0) {
//		Serial.println(character, DEC);
		if ((char) character == '\n') {
			lineBufferNewLine(head, tail, lineIndex);
			return true;
		}
		if(character == 8){
			int i = 0;
			while(Serial1.read() != 'K'){
			}
			if(lineIndex > 0){
				lineIndex--;
				(*head)->lineContents[lineIndex] = ' ';
			}
			return true;
		}
		if (lineIndex == numColumns) {
			lineBufferNewLine(head, tail, lineIndex);
		}
		(*head)->lineContents[lineIndex] = (char) character;
		lineIndex++;
		return true;
	}
	return false;
}

void writeCharacter(char letter, int xChar, int yChar) {
	for (int xDot = 0; xDot < charDimX; xDot++) {
		for (int yDot = 0; yDot < charDimY; yDot++) {
			if (((font[letter][yDot] >> xDot) & 1) != 0) {
				analogWrite(A21, xDot * columnIncrement + xChar * charSepX);
				analogWrite(A22, yDot * rowIncrement + yChar * charSepY);
				delayMicroseconds(10);
				frameCount++;
				if (frameUp) {
					frameUpCount++;
					if (frameUpCount > 10) {
						digitalWrite(33, LOW);
						frameUpCount = 0;
						frameUp = false;
					}
				}
				else if(frameCount == frameRate){
					frameUp = true;
					frameCount = 0;
					digitalWrite(33, HIGH);
				}
			}
		}
	}
}

void writeLine(char* letters, int y) {
	for (int x = 0; x < numColumns; x++) {
		writeCharacter(letters[x], x, y);
	}
}

void writeToScreen(line** head) {
	line* temp = *head;
	for (int y = 0; y < numRows; y++) {
		if (temp->next != nullptr) {
			writeLine(temp->lineContents, y);
			temp = temp->next;
		}
	}
}

void setupIO(){
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	pinMode(15, INPUT);
	digitalWrite(15, HIGH);
	pinMode(16, INPUT);
	digitalWrite(16, HIGH);
	pinMode(17, INPUT);
	digitalWrite(17, HIGH);
	pinMode(18, INPUT);
	digitalWrite(18, HIGH);
	pinMode(19, INPUT);
	digitalWrite(19, HIGH);
	pinMode(33, OUTPUT);
	digitalWrite(33, LOW);
	Serial.begin(115200);
	Serial1.begin(115200);
	analogWriteResolution(12);
	analogReadResolution(10);
}

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

#define numColumns 26

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

int main() {
	line* lineBufferHead = nullptr;
	line* lineBufferTail = nullptr;
	int lineCharacterIndex = 0;
	setupLineBuffer(&lineBufferHead, &lineBufferTail);

	while (true) {
		if (lineNewCharacter(&lineBufferHead, &lineBufferTail, lineCharacterIndex)) {
			line* temp = lineBufferHead;
			Serial.println("=============================================================\n");
			while (temp->next != nullptr) {
				for (int i = 0; i < numColumns; i++) {
					Serial.print(temp->lineContents[i]);
				}
				Serial.print('\n');
				temp = temp->next;
			}
		}
		//		for (int lineSelect = 0; lineSelect < 15; lineSelect++) {
		//			for (int charSelect = 0; charSelect < strlen(display[0]);
		//					charSelect++) {
		//				for (int y = 0; y < maxRows; y++) {
		//					for (int x = 0; x < maxColumns; x++) {
		//						if (((font[display[14 - lineSelect][charSelect]][y] >> x) & 1) != 0) {
		//							analogWrite(A21,x * columnIncrement + charSelect * 157);
		//							analogWrite(A22,y * rowIncrement + lineSelect * 280);
		//							delayMicroseconds(10);
		//						}
		//					}
		//				}
		//			}
		//		}
	}
}

void loop() {
}

void setupLineBuffer(line** head, line** tail) {
	Serial.println("setupLineBuffer");
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
	Serial.println("lineBufferNewLine");
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
	character = Serial.read();
	if (character >= 0) {
		Serial.println("lineNewCharacter");

		if ((char) character == '\n') {
			lineBufferNewLine(head, tail, lineIndex);
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

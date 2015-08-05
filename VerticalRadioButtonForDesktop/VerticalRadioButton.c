#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "VerticalRadioButton.h"
#include "Util.h"

enum KeyCode{
	ENTER = 13, UP = 72, DOWN = 80
};

enum Boolean{
	False, True
};

void VerticalRadioButton_Create(VerticalRadioButton* verticalRadioButton, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint){
	int i;
	for (i = 0; i < count; i++){
		strcpy(verticalRadioButton->items[i], items[i]);
	}
	verticalRadioButton->count = count;
	verticalRadioButton->selectedIndex = 0;
	verticalRadioButton->startPositionToPrint.x = startPositionXToPrint;
	verticalRadioButton->startPositionToPrint.y = startPositionYToPrint;
}

void VerticalRadioButton_Print(VerticalRadioButton* verticalRadioButton){
	int i;
	Point startPositionToPrint = verticalRadioButton->startPositionToPrint;
	CursorUtil_Hide();
	for (i = 0; i < verticalRadioButton->count; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y++);
		if (i == verticalRadioButton->selectedIndex){
			FontUtil_ChangeFontColor(WHITE_INVERSION);
			printf("¡Ý %s", verticalRadioButton->items[i]);
		}
		else{
			FontUtil_ChangeFontColor(WHITE);
			printf("¡Û %s", verticalRadioButton->items[i]);
		}
	}
	FontUtil_ChangeFontColor(WHITE);
}

int VerticalRadioButton_ProcessKey(VerticalRadioButton* verticalRadioButton){
	while (True){
		if (_kbhit()){
			int key = _getch();
			if (key == ENTER){
				break;
			}
			switch (key){
			case 0xE0:
				if (_kbhit()){
					switch (_getch()){
					case UP:
						verticalRadioButton->selectedIndex = (verticalRadioButton->selectedIndex - 1 + verticalRadioButton->count) % verticalRadioButton->count;
						VerticalRadioButton_Print(verticalRadioButton);
						break;
					case DOWN:
						verticalRadioButton->selectedIndex = (verticalRadioButton->selectedIndex + 1) % verticalRadioButton->count;
						VerticalRadioButton_Print(verticalRadioButton);
						break;
					}
				}
				break;
			}
		}
	}
	return verticalRadioButton->selectedIndex;
}

const char* VerticalRadioButton_GetSelectedContent(VerticalRadioButton* verticalRadioButton){
	return verticalRadioButton->items[verticalRadioButton->selectedIndex];
}

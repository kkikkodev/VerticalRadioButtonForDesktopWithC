#ifndef _VERTICAL_RADIOBUTTON_H
#define _VERTICAL_RADIOBUTTON_H
#include "Point.h"

#define ITEMS_COUNT 20
#define ITEMS_CONTENT_SIZE 128

typedef struct _verticalRadioButton{
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE];
	int count;
	int selectedIndex;
	Point startPositionToPrint;
}VerticalRadioButton;

void VerticalRadioButton_Create(VerticalRadioButton* verticalRadioButton, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint);
void VerticalRadioButton_Print(VerticalRadioButton* verticalRadioButton);
int VerticalRadioButton_ProcessKey(VerticalRadioButton* verticalRadioButton);
const char* VerticalRadioButton_GetSelectedContent(VerticalRadioButton* verticalRadioButton);

#endif
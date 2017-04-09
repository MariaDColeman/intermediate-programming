#include <stdio.h>
#include "menuUtil.h"





void printMenu() {
	printf("Main menu:\n");
	printf("\tr <filename> - read image from <filename>\n");
	printf("\tw <filename> - write image to <filename>\n");
	printf("\tc <x1> <y1> <x2> <y2> - crop image to the box with the given corners\n");
	printf("\ti - invert intensities\n");
	printf("\ts - swap color channels\n");
	printf("\tg - convert to grayscale\n");
	printf("\tb <amt> - change brightness (up or down) by the given amount\n");
	printf("\tq - quit\n");
}

int userInput() {
	char firstChar;
	int cond = 1;
	char filename[200];
	int x1;
	int y1;
	int x2;
	int y2;
	float amt;

while(cond) {

	printMenu();
	firstChar = fgetc(stdin);

	switch(firstChar) {
		case 'r':

			scanf(" %s", filename);
			printf("Reading from %s...\n", filename);
			cond = 1;
			break;
		case 'w':

			scanf(" %s", filename);
			printf("Writing to %s...\n", filename);
			cond = 1;
			break;
		case 'c':
			scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
			printf("Cropping region from (%d, %d) to (%d, %d)...\n", x1, y1, x2, y2);
			break;
		case 'i':
			printf("Inverting intensity...\n");
			break;
		case 's':
			printf("Swapping color channels...\n");
			break;
		case 'g':
			printf("Converting to grayscale...\n");
			break;
		case 'b':

			scanf(" %f", &amt);
			printf("Adjusting brightness by %f...\n", amt);
			break;
		case 'q':
			printf("Goodbye!\n");
			cond = 0;
			break;
		default:
			printf("Error: Unknown command\n");
			cond = 1;
			break;
	}

}
	
}


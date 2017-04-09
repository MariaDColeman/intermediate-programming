#include <stdio.h>
#include <stdlib.h>
#include "menuUtil.h"
#include "ppmIO.h"
#include "imageManip.h"
#include "structs.h"



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

void userInput() {
	char firstChar;
	int cond = 1;
	char filename[200];
	int x1;
	int y1;
	int x2;
	int y2;
	float amt;

	Image *im;// = malloc(sizeof(Image));
while(cond) {

	printMenu();
	firstChar = getc(stdin);
	//Image *im = malloc(sizeof(Image));

	switch(firstChar) {
		case 'r':

			scanf(" %s", filename);
			printf("Reading from %s...\n", filename);
			//Image *im = malloc(sizeof(Image));
			//im = readImage(filename);
			im = readImage(filename);
			cond = 1;
			break;
		case 'w':

			scanf(" %s", filename);
			printf("Writing to %s...\n", filename);
			writeImage(im, filename);
			cond = 1;
			break;
		case 'c':
			scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
			printf("Cropping region from (%d, %d) to (%d, %d)...\n", x1, y1, x2, y2);
			//Image* newImage = malloc(sizeof(Image));
			im = crop(im, x1, y1, x2, y2);
			cond = 1;
			break;
		case 'i':
			printf("Inverting intensity...\n");
			invert(im);
			fgetc(stdin); //read newline char
			cond = 1;
			break;
		case 's':
			printf("Swapping color channels...\n");
			swap(im);
			fgetc(stdin); //read newline char
			cond = 1;
			break;
		case 'g':
			printf("Converting to grayscale...\n");
			grayscale(im);
			fgetc(stdin); //read newline char
			cond = 1;
			break;
		case 'b':

			scanf(" %f", &amt);
			printf("Adjusting brightness by %f...\n", amt);
			adjustBrightness(im, amt);
			cond = 1;
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
 return;	
}


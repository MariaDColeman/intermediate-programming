/*File: menuUtil.c

Maria coleman

mcolem31

mcolem31@jhu.edu

EN.600.120 S17

Homework 6

 */

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

    Image *im = NULL;
    while(cond) {

        printMenu();
        firstChar = getc(stdin);


        switch(firstChar) {
        case 'r':
            scanf(" %s", filename);
            printf("Reading from %s...\n", filename);
            /*
            if (im != NULL) {
              free(im->data);
              free(im);
              im=NULL;
            }
            */
            im = readImage(filename);
            getc(stdin);
            cond = 1;
            break;
        case 'w':

            scanf(" %s", filename);
            printf("Writing to %s...\n", filename);
            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                writeImage(im, filename);
            }
            getc(stdin);
            cond = 1;
            break;
        case 'c':
            scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
            printf("Cropping region from (%d, %d) to (%d, %d)...\n", x1, y1, x2, y2);

            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                //im = crop(im, x1, y1, x2, y2);
                crop(im, x1, y1, x2, y2);
            }
            getc(stdin);
            cond = 1;
            break;
        case 'i':
            printf("Inverting intensity...\n");
            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                invert(im);
            }
            fgetc(stdin); //read newline char
            cond = 1;
            break;
        case 's':
            printf("Swapping color channels...\n");
            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                swap(im);
            }
            fgetc(stdin); //read newline char
            cond = 1;
            break;
        case 'g':
            printf("Converting to grayscale...\n");
            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                grayscale(im);
            }
            fgetc(stdin); //read newline char
            cond = 1;
            break;
        case 'b':

            scanf(" %f", &amt);
            printf("Adjusting brightness by %f...\n", amt);
            if (im == NULL) {
                printf("Error: there is no current image\n");
            }
            else {
                adjustBrightness(im, amt);
            }
            getc(stdin);
            cond = 1;
            break;
        case 'q':
            if (im != NULL) {
                /*
                Pixel* temp = NULL;
                for (int i = 0; i < (3 * (im->rows) * (im->cols)); i++) {
                  temp = im->data;
                  free(im->data);
                  im->data++;
                  }

                for (int r = 0; r < im->rows; r++) {
                  for (int c = 0; c < im->cols; c++) {
                free(im->data[(r*(im->cols))+c]);
                  }

                }
                */
                /*
                Pixel *temp;
                for (int i = 0; i < ((im->rows)*(im->cols)); i++) {

                  temp = im->data;
                  (im->data)++;
                  free(temp);
                }
                */
                //free(im->data);
                free(im->data);
                free(im);
            }
            // free(im->data);
            //free(im);
            printf("Goodbye!\n");
            cond = 0;
            break;
        default:
            printf("Error: Unknown command\n");
            while (getc(stdin) != '\n');
            cond = 1;
            break;
        }

    }

}


#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "imageManip.h"
#include "structs.h"


//Image* crop(Image *orig, int x1, int y1, int x2, int y2) {
void crop(Image *orig, int x1, int y1, int x2, int y2) {
    int newRows = y2-y1;
    int newCols = x2-x1;
    //allocate correct space for new pixel array/image?
    //make a new image struct with newRows and newCols

    if ((x1 < 0) || (x1 > orig->cols) || (x2 < 0) || (x2 > orig->cols) || (y1 < 0) || (y1 > orig->rows) || (y2 < 0) || (y2 > orig->rows) || (x1 > x2) || (y1 > y2) ) {

        printf("Error: cropping failed, image unchanged\n");
        //return orig;
        return;
    }
    //free(orig->data);
    Pixel *pix = malloc(sizeof(Pixel) * newRows * newCols);

    int i = 0;
    int cols = orig->cols;
    for (int r = y1; r < y2; r++) {
        for (int c = x1; c < x2; c++) {
            pix[i].red = (orig->data[(r*cols)+c]).red;
            pix[i].green = (orig->data[(r*cols)+c]).green;
            pix[i].blue = (orig->data[(r*cols)+c]).blue;
            i++;
        }
    }
    /*
    if ((x1 < 0) || (x1 > orig->cols) || (x2 < 0) || (x2 > orig->cols) || (y1 < 0) || (y1 > orig->rows) || (y2 < 0) || (y2 > orig->rows) || (x1 > x2) || (y1 > y2)  ) {
      printf("Error: cropping failed, image unchanged\n");
      //free(pix);
      return orig;
    }
    */
    /*
    Image *newImage = malloc(sizeof(Image));

    newImage->data = pix;
    newImage->rows = newRows;
    newImage->cols = newCols;
    newImage->colors = 255;
    free(orig->data);
    free(orig);
    return newImage;
    */
    orig->data = pix;
    orig->rows = newRows;
    orig->cols = newCols;
    orig->colors = 255;
}

void invert(Image *im) {
    int cols = im->cols;
    for (int r = 0; r < im->rows; r++) {
        for (int c = 0; c < im->cols; c++) {
            ((im->data[(r*cols)+c]).red) = (unsigned char) (255 - ((im->data[(r*cols)+c]).red));
            ((im->data[(r*cols)+c]).green) = (unsigned char) 255 - ((im->data[(r*cols)+c]).green);
            ((im->data[(r*cols)+c]).blue) = (unsigned char) 255 - ((im->data[(r*cols)+c]).blue);
        }
    }
}

void grayscale(Image *im) {
    unsigned char intensity;
    int cols = im->cols;
    for (int r = 0; r < im->rows; r++) {
        for (int c = 0; c < im->cols; c++) {
            intensity = (unsigned char) (0.30*((im->data[(r*cols)+c]).red)) + (0.59*((im->data[(r*cols)+c]).green)) + (0.11*((im->data[(r*cols)+c]).blue));
            ((im->data[(r*cols)+c]).red) = intensity;
            ((im->data[(r*cols)+c]).green) = intensity;
            ((im->data[(r*cols)+c]).blue) = intensity;
        }
    }
}

void adjustBrightness(Image *im, float amount) {
    int cols = im->cols;
    int tempValue;
    for (int r = 0; r < im->rows; r++) {
        for (int c = 0; c < im->cols; c++) {

            tempValue = ((im->data[(r*cols)+c]).red) * amount;
            if (tempValue > 255) {
                ((im->data[(r*cols)+c]).red) = 255;
            }

            else if (tempValue < 0) {
                ((im->data[(r*cols)+c]).red) = 0;
            }

            else {
                ((im->data[(r*cols)+c]).red) = (unsigned char) tempValue;
            }

            tempValue = ((im->data[(r*cols)+c]).green) * amount;

            if (tempValue > 255) {
                ((im->data[(r*cols)+c]).green) = 255;
            }
            else if (tempValue < 0) {
                ((im->data[(r*cols)+c]).green) = 0;
            }
            else {
                ((im->data[(r*cols)+c]).green) = (unsigned char) tempValue;
            }

            tempValue = ((im->data[(r*cols)+c]).blue) * amount;
            if (tempValue > 255) {
                ((im->data[(r*cols)+c]).blue) = 255;
            }
            else if (tempValue < 0) {
                ((im->data[(r*cols)+c]).blue) = 0;
            }
            else {
                ((im->data[(r*cols)+c]).blue) = (unsigned char) tempValue;
            }
        }
    }

}


void swap(Image *im) {
    int cols = im->cols;
    for (int r = 0; r < im->rows; r++) {
        for (int c = 0; c < im->cols; c++) {
            unsigned char temp = ((im->data[(r*cols)+c]).red);
            ((im->data[(r*cols)+c]).red) = ((im->data[(r*cols)+c]).green);
            ((im->data[(r*cols)+c]).green) = ((im->data[(r*cols)+c]).blue);
            ((im->data[(r*cols)+c]).blue) = temp;
        }
    }

}


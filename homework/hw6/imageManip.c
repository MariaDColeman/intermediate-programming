#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "imageManip.h"
/*
typedef struct _pixel {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} Pixel;


typedef struct _image {
	Pixel *data;
	int rows;
	int cols;
	int colors;
} Image;
*/
Image* crop(Image *orig, int x1, int y1, int x2, int y2) {
	int newRows = y2-y1;
	int newCols = x2-x1;
	//allocate correct space for new pixel array/image?
	// malloc for Image *newImage;
	//make a new image struct with newRows and newCols
	//mallof for pix which is 
	Pixel *pix = malloc(sizeof(Pixel) * newRows * newCols);

	int i = 0;
	for (int r = y1; r < y2; r++) {
		for (int c = x1; c < x2; c++) {
			pix[i].red = (orig->data[(r*newCols)+c]).red;
			pix[i].green = (orig->data[(r*newCols)+c]).green;
			pix[i].blue = (orig->data[(r*newCols)+c]).blue;
			i++;
		}
	}

	Image *newImage = malloc(sizeof(Image));
	
	newImage->data = pix;
	newImage->rows = newRows;
	newImage->cols = newCols;
	newImage->colors = 255;
	free(orig);
	return newImage;
}

void invert(Image *im) {
  int cols = im->cols;
  for (int r = 0; r < im->rows; r++) {
		for (int c = 0; c < im->cols; c++) {
			((im->data[(r*cols)+c]).red) = 255 - ((im->data[(r*cols)+c]).red);
			((im->data[(r*cols)+c]).green) = 255 - ((im->data[(r*cols)+c]).green);
			((im->data[(r*cols)+c]).blue) = 255 - ((im->data[(r*cols)+c]).blue);
		}
	}
}

void grayscale(Image *im) {
  unsigned char intensity; // = (unsigned char) (0.30*((im->data[(r*newCols)+c]).red)) + (0.59*((im->data[(r*newCols)+c]).green)) + (0.11*((im->data[(r*newCols)+c]).blue));
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


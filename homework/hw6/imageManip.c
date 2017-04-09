#include "imageManip.h"

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

void crop(Image *orig, int x1, int y1, int x2, int y2) {
	int newRows = y2-y1;
	int newCols = x2-x1;
	//allocate correct space for new pixel array/image?
	// malloc for Image *newImage;
	//make a new image struct with newRows and newCols
	//mallof for pix which is 
	Pixel *pix = malloc(sixeof(Pixel) * newRows * newCols);

	int i = 0;
	for (int r = y1; r < y2; r++) {
		for (int c = x1; c < x2; c++) {
			pix[i]->red = (orig.data[(r*newCols)+c])->red;
			pix[i]->green = (orig.data[(r*newCols)+c])->green;
			pix[i]->blue = (orig.data[(r*newCols)+c])->blue;
			i++;
		}
	}

	Image *newImage;
	newImage->data = pix;
	newImage->rows = newRows;
	newImage->cols = newCols;
}

void invert(Image *im) {
	for (int r = 0; r < im.rows; r++) {
		for (int c = 0; c < im.cols; c++) {
			((im->data[(r*newCols)+c]).red) = 255 - ((im->data[(r*newCols)+c]).red);
			((im->data[(r*newCols)+c]).green) = 255 - ((im->data[(r*newCols)+c]).green);
			((im->data[(r*newCols)+c]).blue) = 255 - ((im->data[(r*newCols)+c]).blue);
		}
	}
}

void grayscale(Image *im) {
	unsigned char intensity = (unsigned char) (0.30*((im->data[(r*newCols)+c]).red)) + (0.59*((im->data[(r*newCols)+c]).green)) + (0.11*((im->data[(r*newCols)+c]).blue));
	for (int r = 0; r < im->rows; r++) {
		for (int c = 0; c < im->cols; c++) {
	((im->data[(r*newCols)+c]).red) = intensity;
	((im->data[(r*newCols)+c]).green) = intensity;
	((im->data[(r*newCols)+c]).blue) = intensity;
		}
	}
}

void adjustBrightness(Image *im, float amount) {
	for (int r = 0; r < im->rows; r++) {
		for (int c = 0; c < im->cols; c++) {
			((im->data[(r*newCols)+c]).red) *= amount;
			if (((im->data[(r*newCols)+c]).red) > 255) {
				((im->data[(r*newCols)+c]).red) = 255;
			}
			if (((im->data[(r*newCols)+c]).red) < 0) {
				((im->data[(r*newCols)+c]).red) = 0;
			}
			((im->data[(r*newCols)+c]).green) *= amount;
			if (((im->data[(r*newCols)+c]).green) > 255) {
				((im->data[(r*newCols)+c]).green) = 255;
			}
			if (((im->data[(r*newCols)+c]).green) < 0) {
				((im->data[(r*newCols)+c]).green) = 0;
			}
			((im->data[(r*newCols)+c]).blue) *= amount;
			if (((im->data[(r*newCols)+c]).blue) > 255) {
				((im->data[(r*newCols)+c]).blue) = 255;
			}
			if (((im->data[(r*newCols)+c]).blue) < 0) {
				((im->data[(r*newCols)+c]).blue) = 0;
			}
		}
	}
	
}


void swap(Image *im) {
	for (int r = 0; r < im.rows; r++) {
		for (int c = 0; c < im.cols; c++) {
			unsigned char temp = ((im->data[(r*newCols)+c]).red);
			((im->data[(r*newCols)+c]).red) = ((im->data[(r*newCols)+c]).green);
			((im->data[(r*newCols)+c]).green) = ((im->data[(r*newCols)+c]).blue);
			((im->data[(r*newCols)+c]).blue) = temp;
		}
	}

}


#ifndef IMAGEMANIP_H
#define IMAGEMANIP_H

#include "structs.h"
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


Image* crop(Image *orig, int x1, int y1, int x2, int y2);

void invert(Image *im);

void grayscale(Image *im);

void adjustBrightness(Image *im, float amount);

void swap(Image *im); 

#endif

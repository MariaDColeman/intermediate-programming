#ifndef PPMIO_H
#define PPMIO_H


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

//void checkComments(FILE *fp);

Image* readImage(char filename[]);

void writeImage(Image *im, char filename[]);

#endif

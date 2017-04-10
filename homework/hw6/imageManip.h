#ifndef IMAGEMANIP_H
#define IMAGEMANIP_H

#include "structs.h"


//Image* crop(Image *orig, int x1, int y1, int x2, int y2);
void crop(Image* orig, int x1, int y1, int x2, int y2);


void invert(Image *im);

void grayscale(Image *im);

void adjustBrightness(Image *im, float amount);

void swap(Image *im); 

#endif

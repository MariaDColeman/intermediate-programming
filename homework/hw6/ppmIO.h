#ifndef PPMIO_H
#define PPMIO_H


#include "structs.h"


Image* readImage(char filename[]);

void writeImage(Image *im, char filename[]);

#endif

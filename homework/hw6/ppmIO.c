#include "ppmIO.h"


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


Image* readImage(char filename[]) {


FILE *fp;
//pass in filename string to this function as filename
fp = fopen(filename, "r");
if (fp == NULL) {
	printf("Error: file %s not found\n", filename);
}
else {
	int cols;
	int rows;
	char ch = getc(fp);
	while (ch == '#') {
		while (getc(fp) != '\n');
		ch = getc(fp);
	}
	ch = getc(fp);
	if (ch != '#') {
	ungetc(ch, fp);
	fscanf(fp, " %d", &cols);
}
else{

}



//fclose(fp);
}

Pixel *picture = malloc(sizeof(Pixel) * rows * cols);
int numOfElems = rows * cols;
fread(picture, sizeof(Pixel), numOfElems, fp);
Image *im;
im->data = picture;
im->rows = rows;
im->cols = cols;
im->colors = colors;


}

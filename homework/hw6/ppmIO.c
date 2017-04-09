#include <stdio.h>
#include <stdlib.h>
#include "ppmIO.h"

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
/*
void checkComments(FILE *fp) {
  while (ch == '#') {
    while (getc(fp) != '\n');
    ch = getc(fp);
  }
}
*/

//Image* readImage(char filename[]) {
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
	int colors;
	char ch = getc(fp);
	
	while (ch == '#') {
		while (getc(fp) != '\n');
		//ch = getc(fp);
		//ungetc(fp);
		ch = getc(fp);
	}
	
	//checkComments(fp);
	ungetc(ch, fp);
	ch = getc(fp); //P
	if (ch != 'P') {
	  printf("Error, not P");
	}
	//printf("%c", ch);
	ch = getc(fp); //6
	if (ch != '6') {
	  printf("Error: not 6");
	}
	//printf("%c", ch);


	//ch = getc(fp);
	fscanf(fp, "%*[ \n\t]%c", &ch);

	
	while (ch == '#') {
	  while (getc(fp) != '\n');
	  //ungetc(fp);
	  ch = getc(fp);
	}
	
	//checkComments(fp);
	ungetc(ch, fp);
	fscanf(fp, " %d", &cols);
	//printf("%d\n", cols);
	ch = getc(fp);
	
	while (ch == '#') {
	  while (getc(fp) != '\n');
	  ch = getc(fp);
	}
	
	//checkComments(fp);
	ungetc(ch, fp);
	
	fscanf(fp, " %d", &rows);
	ch = getc(fp);
	
	while (ch == '#') {
	  while (getc(fp) != '\n');
	  ch = getc(fp);
	}
	
	//checkComments(fp);
	ungetc(ch, fp);
	fscanf(fp, " %d", &colors);
	if (colors != 255) {
	  printf("Error: not proper image (not 255)\n");
	}
	getc(fp);



//fclose(fp)

Pixel *picture = malloc(sizeof(Pixel) * rows * cols);
int numOfElems = rows * cols;
fread(picture, sizeof(Pixel), numOfElems, fp);
 Image *im = malloc(sizeof(Image));
im->data = picture;
im->rows = rows;
im->cols = cols;
im->colors = colors;
 fclose(fp);
 return im;
 //fclose(fp);
 }
 return NULL;
}

void writeImage(Image *im, char filename[]) {
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "P6\n");
	fprintf(fp, "%d\n", im->cols);
	fprintf(fp, "%d\n", im->rows);
	fprintf(fp, "%d\n", im->colors);
	fwrite(im->data, sizeof(Pixel), ((im->rows)*(im->cols)), fp);
	free(im);
	fclose(fp); 
}



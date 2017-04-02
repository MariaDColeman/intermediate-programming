#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prompts.h"
#include "functions.h"

/*
Maria Coleman
600,120
4/2/2017
homework 5
mcolem31
mcolem31@jhu.edu
 */




int main() {


 FILE * filehandleIN = fopen("catalog1.txt", "r");
 
  
  int condition = 1;


  if(numLines(filehandleIN)!=15) {
    printf("numLines function is not working properly. the inputted text file has 15 lines\n");
    condition = 0;    
  }

/*
if (condition) {

struct individualCourse * catalog;
catalog = malloc(sizeof(struct individualCourse) * 15);

for(int i=0; i<15; i++) {
  char tempStr[3] = {getc(filehandleIN), getc(filehandleIN), '\0'};
  //catalog[i].courseDiv = {getc(filehandleIN), getc(filehandleIN), '\0'};
  strcpy((catalog[i].courseDiv), tempStr);
  getc(filehandleIN); //read the period character
  char tempStr2[4] = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};
  //catalog[i].courseDep = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};
  strcpy((catalog[i].courseDep), tempStr2);
  getc(filehandleIN); //read the period character
  char tempStr3[4] = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};
  //catalog[i].courseNum = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};
  strcpy((catalog[i].courseNum), tempStr3);
  fscanf(filehandleIN, "%f ", &(catalog[i].credits));
  fgets(catalog[i].courseTitle, 33, filehandleIN); //hoping this will start where it is in line and go to end of line
  //getc(filehandleIN); //hoping this will read the newline character


struct individualCourse *tester = getValidInput(catalog, 15);


 transcriptCourse* head;
 head = malloc(sizeof(transcriptCourse));
assert(head != NULL);






free(catalog);
}

}
*/ // MAYBE DO END TO END TESTING ON EXPECTED OUTPUTS JUST PRINT 














char sem1[] = {'2','0','1','2','.','F','\0'};
char sem2[] = {'2','0','1','3','.','F','\0'};

if(semesterLessThanCheck(sem1,sem2) != 1) {
  printf("semesterLessThanCheck function is not working properly. first is less than second\n");
    condition = 0;    
}

if(semesterGreaterThanCheck(sem1,sem2) != 0) {
  printf("semesterGreaterThanCheck function is not working properly. first is less than second\n");
    condition = 0;    
}


char sem3[] = {'2','0','1','2','.','F','\0'};
char sem4[] = {'2','0','1','2','.','F','\0'};

if(semesterLessThanCheck(sem3,sem4) != 0) {
  printf("semesterLessThanCheck function is not working properly. Entered semesters are equal\n");
    condition = 0;    
}

if(semesterGreaterThanCheck(sem3,sem4) != 0) {
  printf("semesterGreaterThanCheck function is not working properly. Entered semesters are equal\n");
    condition = 0;    
}

char sem5[] = {'2','0','1','2','.','F','\0'};
char sem6[] = {'2','0','1','1','.','F','\0'};

if(semesterLessThanCheck(sem5,sem6) != 0) {
  printf("semesterLessThanCheck function is not working properly\n");
    condition = 0;    
}

if(semesterGreaterThanCheck(sem5,sem6) != 1) {
  printf("semesterGreaterThanCheck function is not working properly\n");
    condition = 0;    
}

char sem7[] = {'2','0','1','2','.','F','\0'};
char sem8[] = {'2','0','1','2','.','S','\0'};

if(semesterLessThanCheck(sem7,sem8) != 0) {
  printf("semesterLessThanCheck function is not working properly. specifically the F/S part\n");
    condition = 0;    
}

if(semesterGreaterThanCheck(sem7,sem8) != 1) {
  printf("semesterGreaterThanCheck function is not working properly. specifically the F/S part\n");
    condition = 0;    
}






  if (condition) {
    printf("All tests passed!\n");
  }

  
fclose(filehandleIN);

}



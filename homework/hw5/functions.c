/*
File: functions.c

Homework 5

600.120 Spring 2017

Maria Coleman

date due: 4/2/17

*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "functions.h"
#include "prompts.h"


//function to figure out number of lines in input file
int numLines(FILE *filehandleIN) {
char c;
 int len = 0;
 for (c = getc(filehandleIN); c != EOF; c = getc(filehandleIN)){
	if (c=='\n') {
		len = len + 1;
	}
}
rewind(filehandleIN);
return len;
} //end numLines



//function to take care of steps b-d in homework prompts
//return a struct or a pointer to a struct of an individual course
struct individualCourse* getValidInput(struct individualCourse *catalog, int len) {
 
        struct individualCourse *inputCoursePtr;
	inputCoursePtr = malloc(sizeof(struct individualCourse));

	char newCourseDiv[3];
	char newCourseDep[4];
	char newCourseNum[4];
	int valid = 1;
	int present = 0;
	
	do {
	course_prompt();
	valid = 1;
	present = 0;
	char newCourseDivTemp[3] = {'0', '0', '\0'};

	int cond=1;
	char c;
	for(int i=0; (cond && (i<2)); i++) {
		c = getc(stdin);
		
		if (c == '\n') {
			valid = 0;
			cond = 0;
			invalid_input_msg();
			clear();
		}
		else {
			newCourseDivTemp[i] = c;
		}
	}
	if (valid) {
	for (int i=0;  i<2; i++) {
		newCourseDivTemp[i] = toupper(newCourseDivTemp[i]); 
	}

	strcpy(newCourseDiv, newCourseDivTemp);

	if ((getc(stdin)) != '.') {
	    invalid_input_msg();
		valid = 0;
		clear();
	}
	else {
	 char newCourseDepTemp[4] = {'0', '0', '0', '\0'};

	cond=1;
	for(int i=0; (cond && (i<3))==1; i++) {
		c = getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			newCourseDepTemp[i] = c;
		}
	}


	 strcpy(newCourseDep, newCourseDepTemp);

	 if ((getc(stdin)) != '.') {
		invalid_input_msg();
		valid = 0;
		clear();
		}
		else {
		  char newCourseNumTemp[4] = {'0', '0', '0', '\0'};
	int cond=1;
	char c;
	for(int i=0; (cond && (i<3))==1; i++) {
		c = getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			newCourseNumTemp[i] = c;
		}
	}

		  strcpy(newCourseNum, newCourseNumTemp);
			  if ((getc(stdin)) != '\n') {
			    invalid_input_msg();
			    valid = 0;
				clear();
			}
		}
	}
}

if (valid) {
//check if the course exists in the catalog

for (int i = 0; i<len; i++) {
	if ((strcmp((catalog[i].courseDiv),newCourseDiv) == 0) && (strcmp((catalog[i].courseDep),newCourseDep) == 0) && (strcmp((catalog[i].courseNum),newCourseNum) == 0)) {
		present = 1;
		inputCoursePtr = &(catalog[i]);
	}

}
if (!present) {
	course_absent_msg();
}
}
	} while ((!valid) || (!present));

return inputCoursePtr;
}


//function to clear the stdin buffer past the newline char from previous input
void clear(void) {
	while(getchar() != '\n');
}



void insertSorted(transcriptCourse **head, struct individualCourse * course2, char semester[], char grade[]) {
  transcriptCourse *p = *head;
  // p=p->next;
  transcriptCourse *q = p;
  while((p->next) != NULL && semesterLessThanCheck((p->semester), semester)) {
		q=p;
		p=p->next;
	}

	transcriptCourse* elem = malloc(sizeof(transcriptCourse));
	(elem->course) = course2;
	//elem->semester = semester;
	strcpy((elem->semester),semester);
	//elem->grade = grade;
	strcpy((elem->grade),grade);
	
	if (p == *head) {
		//first element or empty list
		*head = elem;
		elem->next = p;
	} else {
		//we're in the middle or end
		elem->next = p;
		q->next = elem;
	}
	//	free(course);
}

	



//function to compare whether a semester is "less than" or earlier than another
//returns 1 if first argument is less than second and zero if they're equal or if 1st is greater than 2nd
int semesterLessThanCheck(char sem1[], char sem2[]) {
	int value = 1;
	
char tempSem1[5] = {sem1[0],sem1[1],sem1[2],sem1[3],'\0'};
char tempSem2[5] = {sem2[0],sem2[1],sem2[2],sem2[3],'\0'};
int intSem1 = atoi(tempSem1);
int intSem2 = atoi(tempSem2);
	if(intSem1 > intSem2) {
		value = 0;
	}

	else if (intSem1 == intSem2) {
		if (sem1[5] <= sem2[5]) {
			value = 0;
		}
	}

	return value;
}

void removeSorted(transcriptCourse** phead, struct individualCourse * newIndividualCourse, char semester[]) {
	transcriptCourse* p = *phead;
	transcriptCourse* q = p;


	while(p != NULL && !((strcmp((p->course->courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((p->course->courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((p->course->courseNum),newIndividualCourse->courseNum) == 0) && (strcmp((p->semester),semester)==0))) {
	 //semesterLessThanCheck((p->semester), semester)) {
		q=p;
		p=p->next;
	}
	/*
	if (p == NULL || semesterGreaterThanCheck((p->semester), semester)) {
		//some error
		return;
	}
	*/
	if (p == *phead) {
		//first element
		*phead = p->next;
	} else {
		q->next = p->next;
	}
	free(p);
}

//function to compare whether a semester is "greater than" or later than another
//returns 1 if first argument is greater than second and zero if they're equal or if 1st is less than 2nd
int semesterGreaterThanCheck(char sem1[], char sem2[]) {
	int value = 1;
	
char tempSem1[5] = {sem1[0],sem1[1],sem1[2],sem1[3],'\0'};
char tempSem2[5] = {sem2[0],sem2[1],sem2[2],sem2[3],'\0'};
int intSem1 = atoi(tempSem1);
int intSem2 = atoi(tempSem2);
	if(intSem1 < intSem2) {
		value = 0;
	}

	else if (intSem1 == intSem2) {
		if (sem1[5] >= sem2[5]) {
			value = 0;
		}
	}

	return value;
}

void removeSortedOneCourse(transcriptCourse** phead, struct individualCourse * newIndividualCourse) {
	transcriptCourse* p = *phead;
	transcriptCourse* q = p;


	while(p != NULL && !((strcmp((p->course->courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((p->course->courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((p->course->courseNum),newIndividualCourse->courseNum) == 0))) {
		q=p;
		p=p->next;
	}
	/*
	if (p == NULL || semesterGreaterThanCheck((p->semester), semester)) {
		//some error
		return;
	}
	*/
	if (p == *phead) {
		//first element
		*phead = p->next;
	} else {
		q->next = p->next;
	}
	free(p);
}

void printList(transcriptCourse *head) {
  transcriptCourse* e;
  for(e=head; (e->next)!=NULL; e=e->next) {
		printf("%s %s %s.%s.%s %.1f %s\n", e->semester, e->grade, e->course->courseDiv, e->course->courseDep, e->course->courseNum, e->course->credits, e->course->courseTitle);
	}
}

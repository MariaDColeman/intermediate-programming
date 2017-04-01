/*
File: hw5.c

Homework 5

600.120 Spring 2017

Maria Coleman

date due

*/





//ASK IF WE SHOULD CONVERT INPUT FOR COURSE DEP TO UPPER CASE FIRST THEN COMPARE


//HAVE TO MAKE A SEPARATE .c file FOR SOME REASON


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "prompts.c"


struct individualCourse {
  char courseDiv[3];
  char courseDep[4];
  char courseNum[4];
  float credits;
  char courseTitle[33];
};

typedef struct transcriptCourse {
  struct transcriptCourse *next;
  struct individualCourse course;
  char semester[7];
  char grade[3];
} transcriptCourse;


int numLines(FILE *filehandleIN);
struct individualCourse* getValidInput(struct individualCourse *catalog, int len);
void clear(void);
//transcriptCourse* Create(struct individualCourse *course, char semester[], char grade[]);
//void InsertAfter(transcriptCourse *e, struct individualCourse *course, char semester[], char grade[]);
//void InsertHead(transcriptCourse ** head, struct individualCourse *course, char semester[], char grade[]);
//void DeleteAfter(transcriptCourse *e);
//void DeleteHead(transcriptCourse **head);
int semesterLessThanCheck(char sem1[], char sem2[]);
void insertSorted(transcriptCourse **head, struct individualCourse * course, char semester[], char grade[]);
void removeSorted(transcriptCourse** phead, struct individualCourse * course, char semester[]);
int semesterGreaterThanCheck(char sem1[], char sem2[]);
void removeSortedOneCourse(transcriptCourse** phead, struct individualCourse * course);
void printList(transcriptCourse *head);
/*
//define a struct to represent an individual course
struct individualCourse{
	char courseDiv[3];
	int courseDep;
	int courseNum;
	float credits;
	char courseTitle[33];
};
*/

/*
//define a struct to represent an individual course
struct individualCourse {
	char courseDiv[3];
	char courseDep[4];
	char courseNum[4];
	float credits;
	char courseTitle[33];
};


typedef struct transcriptCourse {
	struct transcriptCourse *next;
	struct individualCourse course;
	char semester[7];
	char grade[3];
} transcriptCourse;
*/
//IDEA: STRCMP TO STRING IN CATALOG ARRAY

int main(int argc, char* argv[]) {

//confirm that a command-line argument is present (and only the name of the catalog text input file)
	if (argc != 2) {
		printf("Usage: hw5 catalog.txt");
		return 1; //exit program because improper number of command-line arguments present
	}

//declare a char array to hold the command-line argument string
//ensure last char is null character
int length = strlen(argv[1]);
char inputFileName[length+1];
strcpy(inputFileName, argv[1]);
inputFileName[length] = '\0';

FILE *filehandleIN;

//open the input file in "read" mode
filehandleIN = fopen(inputFileName, "r");
if (!filehandleIN) {
	printf("Error: Unable to open input catalog file\n");
	return 1;
}


int len = numLines(filehandleIN);

//struct individualCourse catalog[length];

struct individualCourse * catalog;
catalog = malloc(sizeof(struct individualCourse) * len);

for(int i=0; i<len; i++) {
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
}

//REMEMBER TO FREE CATALOG




//struct transcriptCourse * studentTranscript;
transcriptCourse* head;
head = malloc(sizeof(transcriptCourse));
//assert(head != NULL);





char menuInput;
char nextChar;
 struct individualCourse * newIndividualCourse;
 //newIndividualCourse = malloc(sizeof(individualCourse));
 int valid=0;
 char semesterTemp[7];
 char gradeTemp[3];
 do {
	menu_prompt();
	scanf("%c%c", &menuInput, &nextChar);

	while(nextChar != '\n') {
		while(getchar() != '\n');
		menu_prompt();
		scanf("%c%c", &menuInput, &nextChar);
	}

switch(menuInput) {
  int gotostepb = 0;
//if user enters the key for quit
//as an integer Q is 81 and q is 113
case 'q':
case 'Q':
	//maybe free things, maybe put it after switch
	break;

//display the catalog:
case '1':
	for (int i = 0; i < len; i++) {
	printf("%s.%s.%s %.1f %s\n", catalog[i].courseDiv, catalog[i].courseDep, catalog[i].courseNum, catalog[i].credits, catalog[i].courseTitle);
	}	
  break;

//display information on a specific course in the catalog:
case '2':
    newIndividualCourse = getValidInput(catalog, len);
 printf("%s.%s.%s %.1f %s\n", newIndividualCourse->courseDiv, newIndividualCourse->courseDep, newIndividualCourse->courseNum, newIndividualCourse->credits, newIndividualCourse->courseTitle);
  break;

//update the title of a specific course:
case '3':
	//steps b-d in separate function
	newIndividualCourse = getValidInput(catalog, len);
	new_title_prompt();
	char inputStr[34];
	fgets(inputStr, 34, stdin);
	int numOfCharacters = strlen(inputStr);
	while (numOfCharacters >= 33) {
		invalid_input_msg();
		new_title_prompt();
		fgets(inputStr, 34, stdin);
		numOfCharacters = strlen(inputStr);
	}
	char inputStr2[33];
	strncpy(inputStr2,inputStr,33);
//update corresponding course's entry in the catalog with new title
	for (int i = 0; i<len; i++) {
		if ((strcmp((catalog[i].courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((catalog[i].courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((catalog[i].courseNum),newIndividualCourse->courseNum) == 0)) {
		  //catalog[i].courseTitle = inputStr2;
		  strcpy(catalog[i].courseTitle, inputStr2);
		}
	}


	course_updated_msg();

  break;

//update the credit assignment of a specific course:
case '4':
	//steps b-d in separate function
	newIndividualCourse = getValidInput(catalog, len);

new_credit_prompt();
//CHECK PIAZZA TO SEE IF SOMETHING LIKE 16.52 IS OKAYYY AND CHECK IF IT NEEDS .0
	float inputCredits;
	fscanf(stdin, " %f", &inputCredits);
//CAN DO atof if you get it in as a string and check its one digit.one digit
//HAVE TO CHECK THE INVALID PARTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

//if ANY float is valid, then do this..nope not done have to think it though
	//if its 3 digits do like "%c%c%c%c for a newline"
	/*
	scanf(" %f", &menuInput);

	while(nextChar != '\n') {
		while(getchar() != '\n');
		menu_prompt();
		scanf("%c%c", &menuInput, &nextChar);
	}

	this might be good enough if any float is valid!!!!!!!

	while ((scanf(" %f", &inputCredits)) == 0) {
		invalid_input_msg();
		new_credit_prompt;
	}
	*/
//int decimalNumAsInt = (int) (inputCredits*10);

//update corresponding course's entry in the catalog with new title
	for (int i = 0; i<len; i++) {
		if ((strcmp((catalog[i].courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((catalog[i].courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((catalog[i].courseNum),newIndividualCourse->courseNum) == 0)) {
		  
		  catalog[i].credits = inputCredits;
		}
	}


	course_updated_msg();
  break;


//add a course to the student transcript:
case '5':
	
  //int gotostepb = 0;
  //  char semesterTemp[7];// = {'0','0','0','0','0','0','\0'};
  //char gradeTemp[3];
	do {
	//steps b-d in separate function
	newIndividualCourse = getValidInput(catalog, len);

	valid = 0;
	
	while (valid == 0) {
	  valid = 1;

	semester_prompt();
	char stringTemp[7] = {'0', '0', '0', '0', '0', '0', '\0'};
	/*
	if (fscanf(stdin, " %s", stringTemp) == 0) {

	}
	*/
	int cond = 1;
	char c;
	for (int i=0; (cond && (i<7)) == 1; i++) {
		c = getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			stringTemp[i] = c;
		}
	}

	
	
	if (valid != 0) {
	
	if (getc(stdin) != '\n') {
		valid = 0;
		clear();
	}

	//char semesterTemp[7];
	strcpy(semesterTemp, stringTemp);
	
	
	for (int i=0; i<4;i++) {
		if (isdigit(semesterTemp[i])==0) {
			valid = 0;
		}
	}

	if (semesterTemp[4] != '.') {
		valid = 0;
	}

	semesterTemp[5] = toupper(semesterTemp[5]);
	if (semesterTemp[5] != 'F' && semesterTemp[5] != 'S') {
		valid = 0;
	}

}
	
} //end of loop to get proper semester format

valid = 0;

while(valid == 0) {
	valid = 1;
	grade_prompt();
	char tempString[3] = {'0','0','\0'};
	int cond = 1;
	char c;
	for (int i=0; (cond && (i<7)) == 1; i++) {
		c=getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			tempString[i] = c;
		}
	}
if (valid != 0) {

	if (getc(stdin) != '\n') {
		valid = 0;
		clear();
	}
	
	strcpy(gradeTemp, tempString);

	gradeTemp[0] = toupper(gradeTemp[0]);
	int validInv = 0;
	switch(gradeTemp[0]) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'F':
		case 'I':
		case 'S':
		case 'U':
			validInv = 1;
			break;
		default:
			validInv = 0;
			break;
	}
	valid = valid*validInv;
	int validInv2 = 0;
	switch(gradeTemp[1]) {
		case '+':
		case '-':
		case '/':
			validInv2 = 1;
			break;
		default:
			validInv = 0;
			break;
	}
	valid = valid*validInv2;
}

} // end of loop to get proper grade format



//studentTranscript = 
//transcriptCourse *e = Create(newIndividualCourse, semesterTemp, gradeTemp);
 transcriptCourse *e;// = NULL;
//int gotostepb = 0;
//check if the same course with the same semester already exists in the list
int exists = 0;

	if (!head) {
		exists=0;
	}
	for(e=head;e->next!=NULL;e=e->next) {
	if ((strcmp((e->course.courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e->course.courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e->course.courseNum),newIndividualCourse->courseNum) == 0) && (strcmp((e->semester),semesterTemp))) {
		exists = 1;
	} 
	}

	if (exists == 1) {
		duplicate_course_msg();
		gotostepb = 1;
	}
	} while (gotostepb);

//add entry to the transcript list

//void insertSorted(transcriptCourse **head, struct individualCourse * course, char[] semester, char[] grade) 
transcriptCourse **headPtr = &head;
insertSorted(headPtr, newIndividualCourse, semesterTemp, gradeTemp);

transcript_updated_msg();

// look up memcpy
  break;



//remove a course from the student transcript:
case '6':

  gotostepb = 0;
	int exists = 0;

	do  {
	//steps b-d in separate function
	newIndividualCourse = getValidInput(catalog, len);

//check if the course exists in the catalog

	exists = 0;

	if (!head) {
		exists=0;
	}
	transcriptCourse *e;

	for(e=head;(e->next)!=NULL;e=e->next) {
	if ((strcmp((e->course.courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e->course.courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e->course.courseNum),newIndividualCourse->courseNum) == 0)) {
		exists += 1;
	} 
	}

	if (exists == 0) {
		course_absent_msg();
		gotostepb = 1;
	}
} while (gotostepb);

int skip = 0;

if (exists == 1) {
	transcriptCourse **headPtr2= &head;
	removeSortedOneCourse(headPtr2, newIndividualCourse);
	transcript_updated_msg();
	skip = 1;
}

if (!skip) {
	int valid = 0;
	//semesterTemp[7];
	int courseTaken = 0;
while ((valid == 0) || (courseTaken == 0)) {
	valid = 1;

	semester_prompt();
	//char semesterTemp[7];
	char stringTemp[7] = {'0', '0', '0', '0', '0', '0', '\0'};
	/*
	if (fscanf(stdin, " %s", stringTemp) == 0) {

	}
	*/
	int cond = 1;
	char c;
	for (int i=0; (cond && (i<7)) == 1; i++) {
		c = getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			stringTemp[i] = c;
		}
	}

	
	
	if (valid != 0) {
	
	if (getc(stdin) != '\n') {
		valid = 0;
		clear();
	}

	char semesterTemp[7];
	strcpy(semesterTemp, stringTemp);
	
	
	for (int i=0; i<4;i++) {
		if (isdigit(semesterTemp[i])==0) {
			valid = 0;
		}
	}

	if (semesterTemp[4] != '.') {
		valid = 0;
	}

	semesterTemp[5] = toupper(semesterTemp[5]);
	if (semesterTemp[5] != 'F' && semesterTemp[5] != 'S') {
		valid = 0;
	}

	transcriptCourse *e;
	for(e=head;e->next!=NULL;e=e->next) {
	if ((strcmp((e->course.courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e->course.courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e->course.courseNum),newIndividualCourse->courseNum) == 0)) {
		if(strcmp((e->semester),semesterTemp) == 0) {
			courseTaken=1;
		}
	} 
	}

}
	
} //end of loop to get proper semester format and check if course wa taken in that semester

//Delete the specific course from the transcript list
transcriptCourse** headPtr2 = &head;
removeSorted(headPtr2, newIndividualCourse, semesterTemp);

}

  break;

//display the current transcript:
case '7':
	if (head == NULL) {
		empty_transcript_msg();
	}
	else {
		printList(head);

	}
  break;

//display information about a specific course in the transcript:
case '8':
  break;

//compute the cumulative GPA for the student:
case '9':
  break;

default:
   break;

} //end of switch statement

} while ((menuInput != 'q') && (menuInput != 'Q')); //the menuInput variable is equal to Q or q when the user wants to quit

	
fclose(filehandleIN);
filehandleIN = NULL;

return 0;
} //end of main


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
	float newCredits;
	char newCourseTitle[33];
	int valid = 1;
	int present = 0;
	
	do {
	course_prompt();
	valid = 1;
	present = 0;
	char newCourseDivTemp[3] = {'0', '0', '\0'};

	int cond=1;
	char c;
	for(int i=0; (cond && (i<3)); i++) {
		c = getc(stdin);
		if (c == '\n') {
			valid = 0;
			cond = 0;
		}
		else {
			newCourseDivTemp[i] = c;
		}
	}
	//if (valid) 
	for (int i=0;  i<2; i++) {
		newCourseDivTemp[i] = toupper(newCourseDivTemp[i]); 
	}

	strcpy(newCourseDiv, newCourseDivTemp);

	if ((getc(stdin)) != '.') {
		invalid_input_msg();
		valid = 0;

		//for (char c = getc(stdin); c != '\n'; c = getc(stdin));
		clear();
	}
	else {
	 char newCourseDepTemp[4] = {'0', '0', '0', '\0'};

	int cond=1;
	char c;
	for(int i=0; (cond && (i<4))==1; i++) {
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
		//for (char c = getc(stdin); c != '\n'; c = getc(stdin));
		clear();
		}
		else {
		  char newCourseNumTemp[4] = {'0', '0', '0', '\0'};
	int cond=1;
	char c;
	for(int i=0; (cond && (i<4))==1; i++) {
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
			    //for (char c = getc(stdin); c != '\n'; c = getc(stdin));
				clear();
			}
		}
	}

if (valid) {
//check if the course exists in the catalog

for (int i = 0; i<len; i++) {
	if ((strcmp((catalog[i].courseDiv),newCourseDiv) == 0) && (strcmp((catalog[i].courseDep),newCourseDep) == 0) && (strcmp((catalog[i].courseNum),newCourseNum) == 0)) {
		present = 1;
		newCredits = catalog[i].credits;
		//newCourseTitle = catalog[i].courseTitle;
		strcpy(newCourseTitle, (catalog[i].courseTitle));
	}

}
if (!present) {
	course_absent_msg();
}
}
	} while ((!valid) || (!present));

	/*
//put into struct
inputCoursePtr->courseDiv = newCourseDiv;
inputCoursePtr->courseDep = newCourseDep;
inputCoursePtr->courseNum = newCourseNum;
inputCoursePtr->credits = newCredits;
inputCoursePtr->courseTitle = newCourseTitle;
	*/
	strcpy((inputCoursePtr->courseDiv), newCourseDiv);
	strcpy((inputCoursePtr->courseDep), newCourseDep);
	strcpy((inputCoursePtr->courseNum), newCourseNum);
	inputCoursePtr->credits = newCredits;
	strcpy((inputCoursePtr->courseTitle), newCourseTitle);
return inputCoursePtr;
}


//function to clear the stdin buffer past the newline char from previous input
void clear(void) {
	while(getchar() != '\n');
}


transcriptCourse* Create(struct individualCourse * course, char semester[], char grade[]) {
	transcriptCourse *e = malloc(sizeof(transcriptCourse));
	assert(e);
	e->next = NULL;
	e->course = *course;
	//e->semester = semester;
	strcpy((e->semester),semester);
	//e->grade = grade;
	strcpy((e->grade),grade);
	return e;
}
/*
void InsertAfter(transcriptCourse *e, struct individualCourse *course, char[] semester, char[] grade) {
	transcriptCourse *newE = Create(course, semester, grade);
	newE->next = e->next;
	e->next = newE;
}

void InsertHead(transcriptCourse **head, struct individualCourse *course, char[] semester, char[] grade) {
	transcriptCourse *e = Create(course, semester, grade);
	e->next = *head;
	*head = e;
}

void DeleteAfter(transcriptCourse *e) {
	transcriptCourse* eNext = e->next;
	if(!eNext) return;
	e->next = e->next->next;
	free(eNext);
}

void DeleteHead(transcriptCourse **head) {
	transcriptCourse** e = (*head);
	*head = e->next;
	free(e);
}
*/
void insertSorted(transcriptCourse **head, struct individualCourse * course, char semester[], char grade[]) {
	transcriptCourse *p = *head;
	transcriptCourse *q = p;
	while(p != NULL && semesterLessThanCheck((p->semester), semester)) {
		q=p;
		p=p->next;
	}

	transcriptCourse * elem = malloc(sizeof(transcriptCourse));
	elem->course = *course;
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


	while(p != NULL && !((strcmp((p->course.courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((p->course.courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((p->course.courseNum),newIndividualCourse->courseNum) == 0) && (strcmp((p->semester),semester)==0))) {
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


	while(p != NULL && !((strcmp((p->course.courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((p->course.courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((p->course.courseNum),newIndividualCourse->courseNum) == 0))) {
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
	for(transcriptCourse* e=head; e!=NULL; e=e->next) {
		printf("%s %s %s.%s.%s %f %s\n", e->semester, e->grade, e->course.courseDiv, e->course.courseDep, e->course.courseNum, e->course.credits, e->course.courseTitle);
	}
}

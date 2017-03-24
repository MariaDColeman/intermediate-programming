/*
File: hw5.c

Homework 5

600.120 Spring 2017

Maria Coleman

date due

*/





//ASK IF WE SHOULD CONVERT INPUT FOR COURSE DEP TO UPPER CASE FIRST THEN COMPARE



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prompts.c"

int numLines(FILE *filehandleIN);
struct individualCourse* getValidInput(struct individualCourse *catalog, int len);

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

//define a struct to represent an individual course
struct individualCourse {
	char courseDiv[3];
	char courseDep[4];
	char courseNum[4];
	float credits;
	char courseTitle[33];
};


struct transcriptCourse {
	struct transcriptCourse *next;
	struct individualCourse course;
	char year[5];
	char semester;
	char grade[3];
};

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










char menuInput;
char nextChar;
 struct individualCourse * newIndividualCourse;
 
do {
	menu_prompt();
	scanf("%c%c", &menuInput, &nextChar);

	while(nextChar != '\n') {
		while(getchar() != '\n');
		menu_prompt();
		scanf("%c%c", &menuInput, &nextChar);
	}

switch(menuInput) {

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
	fscanf(stdin, "%f ", inputCredits);
//CAN DO atof if you get it in as a string and check its one digit.one digit
//HAVE TO CHECK THE INVALID PARTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT

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
	//steps b-d in separate function
	newIndividualCourse = getValidInput(catalog, len);

	semester_prompt();

  break;

//remove a course from the student transcript:
case '6':
  break;

//display the current transcript:
case '7':
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
	char newCourseDivTemp[3] = {(getc(stdin)), (getc(stdin)), '\0'};
	strcpy(newCourseDiv, newCourseDivTemp);
	if ((getc(stdin)) != '.') {
		invalid_input_msg();
		valid = 0;

		for (char c = getc(stdin); c != '\n'; c = getc(stdin));
	}
	else {
	 char newCourseDepTemp[4] = {getc(stdin), getc(stdin), getc(stdin), '\0'};
	 strcpy(newCourseDep, newCourseDepTemp);
	 if ((getc(stdin)) != '.') {
		invalid_input_msg();
		valid = 0;
		for (char c = getc(stdin); c != '\n'; c = getc(stdin));
		}
		else {
		  char newCourseNumTemp[4] = {getc(stdin), getc(stdin), getc(stdin), '\0'};
		  strcpy(newCourseNum, newCourseNumTemp);
			  if ((getc(stdin)) != '\n') {
			    invalid_input_msg();
			    valid = 0;
			    for (char c = getc(stdin); c != '\n'; c = getc(stdin));
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

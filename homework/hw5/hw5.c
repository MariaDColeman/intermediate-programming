/*
File: hw5.c

Homework 5

600.120 Spring 2017

Maria Coleman

date due

*/

#include <stdio.h>
#include <string.h>
#include "prompts.c"


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



int menuInput;
char nextChar;

do {
	menu_prompt();
	scanf("%d%c", &menuInput, &nextChar);

	while(nextChar != '\n') {
		while(getchar() != '\n');
		menu_prompt();
		scanf("%d%c", &menuInput, &nextChar);
	}

switch(menuInput) {

//if user enters the key for quit
//as an integer Q is 81 and q is 113
case 81:
case 113:
	//maybe free things, maybe put it after switch
	break;

//display the catalog:
case 1:
  break;
//display information on a specific course in the catalog:
case 2:
  break;
//update the title of a specific course:
case 3:
  break;
//update the credit assignment of a specific course:
case 4:
  break;
//add a course to the student transcript:
case 5:
  break;
//remove a course from the student transcript:
case 6:
  break;
//display the current transcript:
case 7:
  break;
//display information about a specific course in the transcript:
case 8:
  break;
//compute the cumulative GPA for the student:
case 9:
  break;

default:
   break;

} //end of switch statement

} while ((menuInput != 81) && (menuInput != 113)); //the menuInput variable is equal to 81 for Q and 113 for q when the user wants to quit

	


} //end of main

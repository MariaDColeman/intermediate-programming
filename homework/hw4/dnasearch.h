#include <stdio.h>


//function declarations

// function to check whether the inputted text is valid (doesn't have something other than A,C,G,or T (upper or lower case) for a non-whitespace character and the number of A/C/G/T characters is not 0 and not greater than 15000
int invalidTextFileCheck(FILE *filehandleIN, int maxLength, int code);



int extractPatterns(FILE *filehandleIN, int counter, char** patterns); //char* patterns[]


int onePattern(FILE *filehandleIN, int counter, char onePattern[]) ;


// function to check whether inserted character is valid (upper or lower case A,C,G, or T)
int invalidCharCheck(char c);

// assuming the text is valid, store in an array of characters
void createArrayFromFile(FILE *filehandleIN, int counter, char array[]);


//int* offsets(char arrayFromFile[], int lengthArrayFromFile, char pattern[], int lengthOfPatterns[]);



//int[] findAllMatches(char pattern[], FILE *filehandleIN);



//int findNextMatch(char pattern[], FILE *filehandleIN, int offset);


int outputs(char** patterns, int numOfPatterns, char arrayFromFile[]); //char* extractPatterns[]

void indexOfPatternInText(char arrayFromFile[], char pattern[], int lengthText, int lengthPattern);

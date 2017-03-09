#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dnasearch.h"

/*
Maria Coleman
600.120
3/8/2017
Homework 4
mcolem31
mcolem31@jhu.edu
 */



int main(int argc, char* argv[]) {

  //Confirm that one and only one command-line argument is present in addition to the executable name and command to run it
  if (argc != 2) {
    printf("Usage: hw4 textFileName.txt\n");
    return 1;
  }

  
  //Declare and initialize a char array to hold the comman-line argument string;
  int length1 = strlen(argv[1]);
  char inFileName[length1 + 1];
  strcpy(inFileName, argv[1]);
  inFileName[length1] = '\0';

  FILE *filehandleIN;

  //open the input file in "read" mode
  filehandleIN = fopen(inFileName, "r");

  
  int resultInvalidCheck = invalidTextFileCheck(filehandleIN, 15000, 0);
  //  printf("%d", resultInvalidCheck);
  if ((resultInvalidCheck == 0) || (resultInvalidCheck == 1)) {
    printf("Invalid text file");
    return 2;
  }

  int numOfPatterns=-2;
  
  char** patterns = NULL;
  
  
  numOfPatterns  = extractPatterns(stdin, resultInvalidCheck, patterns); 
 if (numOfPatterns == -1) {
   return -1;
 }

  char arrayFromFile[resultInvalidCheck];
  createArrayFromFile(filehandleIN, resultInvalidCheck, arrayFromFile); //if not invalid, then resultInvalidCheck equals the number of valid "A, T, C, G" characters

  
  outputs(patterns, numOfPatterns, arrayFromFile); 

 
  
  fclose(filehandleIN);
  return 0;

} //end of main

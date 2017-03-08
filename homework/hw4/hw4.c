#include <stdio.h>
#include <string.h>
#include "dnasearch.h"

int main(int argc, char* argv[]) {

  //Confirm that one and only one command-line argument is present in addition to the executable name and command to run it
  if (argc != 1) {
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
  filehandleIN = fopen(inputFileName, "r");

  resultInvalidCheck = invalidTextFileCheck(filehandleIN, 15000);
  
  if ((resultInvalidCheck == 0) || (resultInvalidCheck == 1)) {
    printf("Invalid text file");
    return 2;
  }

  int numOfPatterns;
  char* extractedPatterns[];
numOfPatterns  = extractPatterns(stdin, resultInvalidCheck, extractedPatterns);
  
  /*
  char arrayFromFile[resultInvalidCheck];
  arrayFromFile = createArrayFromFile(filehandleIN, resultInvalidCheck); //if not invalid, then resultInvalidCheck equals the number of valid "A, T, C, G" characters

    
 resultInvalidCheckSTDIN = invalidTextFileCheck(stdin, resultInvalidCheck);

 While ((resultInvalidCheckSTDIN == 0) || (resultInvalidCheckSTDIN == -1)) {
 
 if (resultInvalidCheckSTDIN == 0) {
   printf("Invalid pattern");
   return 3;
 }

 while (resultInvalidCheckSTDIN == -1) {
   resultInvalidCheckSTDIN = invalidTextFileCheck(stdin, resultInvalidCheck);
 }

 }
 
 
 char arrayFromSTDIN[resultInvalidCheckSTDIN];
 arrayFromSTDIN = createArrayFromFile(stdin, resultInvalidCheckSTDIN);
  */

 outputs(extractedPatterns, numOfPatterns)
  
  
  fclose(filehandleIN);
  return 0;

} //end of main

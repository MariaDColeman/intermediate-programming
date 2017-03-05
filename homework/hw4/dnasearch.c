#include "dnasearch.h"
#include <stdio.h>
#include <stdio.h>

//function definitions

//check for invalid text file; return 0 if invalid
int invalidTextFileCheck(FILE *filehandleIN, int maxLength) {

  int counter=0;
  char character;
  //for somethin till eof
  //for (int i = 0; i < 15002; i++)
  while ((fscanf(filehandleIN, "%c", &character) != 0)&&(character != EOF)) {
  while(!isspace(character)) {
    //if invalid character
    if (invalidCharCheck(character) == 0) {
       return 0;
    }
    else if (counter > maxLength) {
       return 0;
    }
    else {
    counter += 1;
    }
  } //end of while loop
  } //end of outer while loop
  if (counter == 0) {
    return -1; //probably change back to 0
  }
  else {
  return counter;
  }
} //end of invalidTextFileCheck




//extract first pattern from stdin
char[] extractPattern(FILE *filehandleIN) {
  char character;
  char pattern[];
  int i = 0;
  
  while ((fscanf(filehandleIN, "%c", &character) != 0)&&(!isspace(character))) {
    if (invalidCharCheck(character)) {
      pattern[i] = character;
      i += 1;
    } //end of if
    else {
      return;
    }

  } //end of while
  return pattern;

} //end of extractPattern










//check for invalid character; return 0 if invalid
int invalidCharCheck(char c) {
  toUpper(c);
  if ((c != 'A') || (c != 'C') || (c != 'G') || (c != 'T')) {
    return 0;
  } //end of if

  else {
    return 1;
  }
}


//store text from file in an array of characters
char[] createArrayFromFile(FILE *filehandleIN, int counter) {

  char character;
  char array[counter];

 for (int i = 0; i < counter; i++) {
  while ((fscanf(filehandleIN, "%c", &character) != 0)&&(!isspace(character))) {

    //while(!isspace(character)) {
      array[i] = character;
      //} //end of inner while loop
  } //end of while loop
 } //end of for loop
  
 return array;
} //end of createArrayFromFile






//store text from stdin in an array of strings
char* [] createArrayFromSTDIN(FILE *filehandleIN, int counter) {

  char character;
  char pattern
    char* arrayOfPatterns[];
  int i = 0;
  arrayOfPatterns[i] = extractPattern(stdin, );
  if (arrayOfPatterns[i] == NULL) {
    return;
  }
    
  return arrayOfPatterns;
}











//output list of offsets where the pattern occurs in the text from the file
int[] offsets(char arrayFromFile[], int lengthArrayFromFile, char* arrayFromSTDIN[], int lengthArrayFromSTDIN) {
  int offsetsArray[];
  int offsets = 0;
  int match = 1;
  for (int i=0; i < (lengthArrayFromFile - lengthArrayFromSTDIN); i++) {
  start:
    match = 1;
    for (int j = 0; j <= lengthArrayFromSTDIN; j++) {
    
      if ((*arrayFromSTDIN[i])[j] != arrayFromFile[i+j]) {
	match = 0;
	goto start;//break; //HAVE TO BREAK OUT OF BOTH??
      }
      if (match) {
	offsets += i;
      }
    } //end of inner for loop

    

  } //end of outer for loop
  
  return offsetsArray;
} //end of offsets


//maybe first go through and check if each pattern is valid. then find offsets of each pattern so you just send in one pattern above at a time

#include "dnasearch.h"
#include <stdio.h>
#include <stdio.h>

//function definitions

//check for invalid text file; return 0 if invalid
//code is to use to test patterns. if code is something then we know its doing the user patterns
int invalidTextFileCheck(FILE *filehandleIN, int maxLength, int code) {

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
  if (code == 3) { //my code meaning user input patterns case
    return counter; //this is so no spaces are allowed
  }
    
  } //end of outer while loop
  if (counter == 0) {
    return -1; //probably change back to 0
  }
  else {
  return counter;
  }
  
} //end of invalidTextFileCheck




//extract patterns from stdin
//counter is max length of 1 pattern (length of text size) maybe from main
int extractPatterns(FILE *filehandleIN, int counter, char*[] patterns) {
  /*
  char character;
  char* patterns[];
  int i = 0;
  char onePattern[];
  
  while ((fscanf(filehandleIN, "%c", &character) != 0)&&(character!=EOF)

  while ((!isspace(character))) {
    if (invalidCharCheck(character)) {
      onePattern[i] = character;
      i += 1;
    } //end of if
    else if (i > counter) {
      return NULL;
    }
    else {
      return NULL;
    }

	 }
	 }//end of while
  
  return patterns;
  */

  //new idea:

  char* patterns[];
  char somePattern[];
  int c;
  c = getc(filehandleIN);
  while ( c!= EOF) {
    ungetc(c, filehandleIN);
    
  somePattern = onePattern(filehandleIN, counter); // maybe combine in one line

 
    
  if (somePattern == NULL) {
    //print some error or something
    return 1;
  }

  // while (somePattern != NULL) {
  else {
  patterns[i] = somePattern;
    somePattern = onePattern(stdin, counter);
    i++;
  }

  return i; //i is the number of patterns
  
  }

  

} //end of extractPatterns


//extract one pattern
//filehandleIN should be stdin
//input counter probably from main (or function that calls this which gets it from main)
char[] onePattern(FILE *filehandleIN, int counter) {
  lengthOfPattern = invalidTextFileCheck(filehandleIN, counter, 3); //3 is the code for this user pattern input case: see function definition
  if (!(lengthOfPattern)) {
    return 1; //SOME ERRRORRRR CODE maybe null
  }

  char onePattern[lengthOfPattern];
  int successNum = 0;
  
  for(int i=0; i < lengthOfPattern; i++) {
    successNum = fscanf(filehandleIN, "%c", onePattern[i])
      if (!(successNum)) {
	return 1; //SOME ERROR CODE maybe null
      }
  }
  return onePattern;

}







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
//send in counter as the length of the text in the file!!
//but we want it to be max of one pattern not num of patterns
char* [] createArrayFromSTDIN(FILE *filehandleIN, int counter) {

  char character;
  char pattern
    char* arrayOfPatterns[];
  int i = 0;
  while ((fscanf(filehandleIn, "%c", &character)!=0)&&(character != EOF) {
  arrayOfPatterns[i] = extractPattern(stdin, counter );
  if (arrayOfPatterns[i] == NULL) {
    return;
  }
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


int[] findAllMatches(char pattern[], FILE *filehandleIN) {

  int offsets[];

  offset = 0;
  findNextMatch(pattern, stdin, offset);


  return offsets;

} //end of findAllMatches





int findNextMatch(char pattern[], FILE *filehandleIN, int offset) {
  int newOffset;

  return newOffset;
  
  
} //end of findNextMatch


  //somehing calls findAllMatches(extractedPatterns[i], filehandleIN);


  int outputs(char* extractedPatterns[], int numOfPatterns) {

    for (int i=0; i<numOfPatterns; i++) {
    
    findAllMatches(extractedPatterns[i]);
    printArray(offsets);
    }


    return 0;
  }//end of outputs


  
  int printArray(int offsets[], int num) {


  }

#include "dnasearch.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//function definitions

//check for invalid text file; return 0 if invalid
//code is to use to test patterns. if code is something then we know its doing the user patterns
int invalidTextFileCheck(FILE *filehandleIN, int maxLength, int code) {

  int counter=0;
  char character;
  //for somethin till eof
  //for (int i = 0; i < 15002; i++)
  while ((fscanf(filehandleIN, " %c ", &character) != 0)&&(character != EOF)) {
    if(!isspace(character)) {
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
  }
  } //end of while loop

  if (code == 3) { //my code meaning user input patterns case
    return counter; //this is so no spaces are allowed
  }
    
  if (counter == 0) {
    return -1; //probably change back to 0
  }
  else {
  return counter;
  }
  
} //end of invalidTextFileCheck





//counter is max length of 1 pattern (length of text size) maybe from main
int extractPatterns(FILE *filehandleIN, int counter, char** patterns) { //char* patterns[]
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

  // char* patterns[] = patterns;
  char* somePattern=NULL; //char somePattern[]
  int lengthOfPattern;

  int c;
  c = getc(filehandleIN);
  int i = 0;
  //int d;
    while (c != EOF) {
    ungetc(c, filehandleIN);
    lengthOfPattern = -1;
    lengthOfPattern = onePattern(filehandleIN, counter, somePattern); // maybe combine in one line
    //lengthOfPatterns[i] = lengthOfPattern;
 
    
  if (lengthOfPattern == -1) {
    //print some error or something
    return -1;
  }
  else if (lengthOfPattern == 0) {
    return 3;
    printf("Something wrong with putting pattern together");
  }

  // while (somePattern != NULL) {
  else {
  patterns[i] = somePattern;
   onePattern(stdin, counter, somePattern);
    i++;
  }
  
  }

  return i; //i is the number of patterns
  
 
} //end of extractPatterns


//extract one pattern
//filehandleIN should be stdin
//input counter probably from main (or function that calls this which gets it from main)
int onePattern(FILE *filehandleIN, int counter, char onePatternArray[]) {

  int lengthOfPattern = invalidTextFileCheck(filehandleIN, counter, 3); //3 is the code for this user pattern input case look at function definition
  if (!(lengthOfPattern)) {
    printf("Invalid text file");
    return -1; //SOME ERRRORRRR CODE maybe null
  }

  //char onePattern[lengthOfPattern];
  int successNum = 0;
  
  for(int i=0; i < lengthOfPattern; i++) {
    successNum = fscanf(filehandleIN, "%c", &onePatternArray[i]);
      if (!(successNum)) {
	return 0; //SOME ERROR CODE maybe null
      }
  }
  onePatternArray[lengthOfPattern]='\0';
  return lengthOfPattern;
  
}







//check for invalid character; return 0 if invalid
int invalidCharCheck(char c) {
 c = toupper(c);
  if ((c != 'A') || (c != 'C') || (c != 'G') || (c != 'T')) {
    return 0;
  } //end of if

  else {
    return 1;
  }
}


//store text from file in an array of characters
void createArrayFromFile(FILE *filehandleIN, int counter, char array[]) {

  char character;
  //char array[counter];

 for (int i = 0; i < counter; i++) {
  while ((fscanf(filehandleIN, "%c", &character) != 0)&&(!isspace(character))) {

    //while(!isspace(character)) {
      array[i] = character;
      //} //end of inner while loop
  } //end of while loop
 } //end of for loop
 array[counter] = '\0';
 
} //end of createArrayFromFile

//or fscanf(filehandleIN, "[ 


/*

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

*/







/*

//output list of offsets where the pattern occurs in the text from the file
int* offsets(char arrayFromFile[], int lengthArrayFromFile, char pattern[], int lengthOfPattern) {
  int *offsetsArray;
  int offsets = 0;
  int match = 1;
  int k = 0;
  for (int i=0; i < (lengthArrayFromFile - lengthOfPattern); i++) {
  
    match = 1;
    for (int j = 0; j <= lengthOfPattern; j++) {
    
      if ((pattern[j]) != arrayFromFile[i+j]) {
	match = 0;
	goto start;//break; //HAVE TO BREAK OUT OF BOTH??
      }
      if (match) {
	*offsetsArray = i;
	offsetsArray++;
	//k++;
      }
    } //end of inner for loop
  start:
    

  } //end of outer for loop
  
  return offsetsArray;
} //end of offsets
*/

//maybe first go through and check if each pattern is valid. then find offsets of each pattern so you just send in one pattern above at a time
/*

int* findAllMatches(char pattern[], char arrayFromFile[], int resultInvalidCheck) {

  int *offsets;

  offset = 0;
  findNextMatch(pattern, arrayFromFile, *offsets, resultInvalidCheck);


  return offsets;

} //end of findAllMatches

*/


/*
int findNextMatch(char pattern[], char arrayFromFile[], int offset, int lengthArrayFromFile) {
  int newOffset = offset;

  offsets(arrayFromFile, lengthArrayFromFile, pattern[i], lengthOfPattern)
  return newOffset;
  
  
} //end of findNextMatch


  //somehing calls findAllMatches(extractedPatterns[i], filehandleIN);
  */

int outputs(char* extractedPatterns[], int numOfPatterns, char arrayFromFile[]) { //char* extractedPatterns
  //int x=0;
  //int index[]; ?????????????
    for (int i=0; i<numOfPatterns; i++) {
    
      //  findAllMatches(extractedPatterns[i], arrayFromFile, resultInvalidCheck);
      // printArray(offsets);

      //  offsets(arrayFromFile, resultInvalidCheck,extractedPatterns[i], lengthOfPatterns[i]); 
      int lengthText = strlen(arrayFromFile);
      int lengthPattern = strlen(extractedPatterns[i]);
      printf("%s ", extractedPatterns[i]);
      indexOfPatternInText(arrayFromFile, extractedPatterns[i], lengthText, lengthPattern); //starting position
      printf("\n");
    }


    return 0;
    
  }//end of outputs


  
// int printArray(int offsets[], int num) {


//}



void indexOfPatternInText(char arrayFromFile[], char pattern[], int lengthText, int lengthPattern) {

  int condition = 0;
  int k=0;
  for(int i=0; i<(lengthText-lengthPattern); i++) {
    k=i;
    for(int j=0; j<lengthPattern; j++) {

    if (arrayFromFile[i] == pattern[j]) {
      condition = 1;
      i++;
    }
    }
    if (condition == 1) {
      //return k;
      printf("%d ", k);
    }
    i=k;
  }
  if (k == 0) {
    printf("Not found");
  }
  

}





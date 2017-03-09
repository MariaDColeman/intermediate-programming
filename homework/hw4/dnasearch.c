#include "dnasearch.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



/*
Maria Coleman
600,120
3/8/2017
Homework 4
mcolem31
mcolem31@jhu.edu
 */









//function definitions

//check for invalid text file; return 0 if invalid
//code is to use to test patterns. if code is something then we know its doing the user patterns
int invalidTextFileCheck(FILE *filehandleIN, int maxLength, int code) {

  int counter=0;
 
  
  
 
  int character;
 
  while((character = fgetc(filehandleIN)) != EOF) {
 
 
 
 
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
    return -1; 
  }
  else {
  return counter;
  }
  
} //end of invalidTextFileCheck






int extractPatterns(FILE *filehandleIN, int counter, char** patterns) { 

  char* somePattern=NULL;
  int lengthOfPattern;

  int c;
  c = fgetc(filehandleIN);
  int i = 0;
  
    while (c != EOF) {
    ungetc(c, filehandleIN);
    lengthOfPattern = -1;
    lengthOfPattern = onePattern(filehandleIN, counter, somePattern); 
   
    
  if (lengthOfPattern == -1) {
    //print some error or something
    return -1;
  }
  else if (lengthOfPattern == 0) {
    return 3;
    printf("Something wrong with putting pattern together");
  }

  
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
    printf("Invalid pattern");
    return -1; 
  }

  
  int successNum = 0;
  
  for(int i=0; i < lengthOfPattern; i++) {
    successNum = fscanf(filehandleIN, "%c", &onePatternArray[i]);
      if (!(successNum)) {
	return 0; 
      }
  }
  onePatternArray[lengthOfPattern]='\0';
  return lengthOfPattern;
  
}







//check for invalid character; return 0 if invalid
int invalidCharCheck(char c) {
 c = toupper(c);
  if ((c != 'A') && (c != 'C') && (c != 'G') && (c != 'T')) {
    return 0;
  } //end of if

  else {
    return 1;
  }
}


//store text from file in an array of characters
void createArrayFromFile(FILE *filehandleIN, int counter, char array[]) {

  int character;
  

 for (int i = 0; i < counter; i++) {
  
    while(((character=fgetc(filehandleIN)) != EOF)&&(!isspace(character))) {
  
      array[i] = character;
  
  }
 } array[counter] = '\0';
 
} 












int outputs(char* extractedPatterns[], int numOfPatterns, char arrayFromFile[]) { //char* extractedPatterns
  //int x=0;
  //int index[]; ?????????????
    for (int i=0; i<numOfPatterns; i++) {
    
     

      
      int lengthText = strlen(arrayFromFile);
      int lengthPattern = strlen(extractedPatterns[i]);
      printf("%s ", extractedPatterns[i]);
      indexOfPatternInText(arrayFromFile, extractedPatterns[i], lengthText, lengthPattern); //starting position
      printf("\n");
    }


    return 0;
    
  }//end of outputs


  



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
     
      printf("%d ", k);
    }
    i=k;
  }
  if (k == 0) {
    printf("Not found");
  }
  

}





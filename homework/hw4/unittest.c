#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dnasearch.h"


int main() {


  //  FILE *filehandleIN;
 FILE * filehandleINinvalid = fopen("invalidTextFile.txt", "r");
 FILE * filehandleINvalid = fopen("validTextFile.txt", "r");
  
  int condition = 1;


  if((invalidTextFileCheck(filehandleINinvalid, 15000, 0))!=0) {
    printf("invalidTextFileCheck function is not working properly. the inputted text file is not valid in terms of its characters.");
    condition = 0;    
  }

  if((invalidTextFileCheck(filehandleINvalid, 0, 0))!=0) {
    printf("invalidTextFileCheck function is not working properly. The maximum length was entered as 0.");
    condition = 0;
  }

  if((invalidTextFileCheck(filehandleINvalid, 15000, 3)) ==0) {
    printf("invalidTextFileCheck function is not working properly because valid input was entered.");
    condition = 0;
  }
  

  if((invalidCharCheck(y) == 1)) {
    printf("invalidCharCheck function is not working properly since y is not valid.")
      condition = 0;
      }

  if((invalidCharCheck(c) == 1)) {
    printf("invalidCharCheck function is not working properly because c is valid, just like C is")
      condition = 0;
  }




  if((createArrayFromFile("validTextFile.txt", 5, [w e r])) != void) {
    printf("createArrayFromFile isn't working greater since it should be void.")
      condition = 0;
  }


  if((outputs(






  if (condition) {
    printf("All tests passed!");
  }

  





}

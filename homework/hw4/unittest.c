#include <stdio.h>
#include "dnasearch.h"


int main() {


  FILE *filehandleIN;
  filehandleINinvalid = fopen(invalidTextFile.txt, "r");
  filehandleINvalid = fopen(validTextFile.txt, "r");
  
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

  if((extractPatterns(filehandleINvalid, 10, {"ATA" "TGT"})) == -1) {
    printf("extractPatterns function isn't working properly because the input is valid.");
  }

















  if (condition) {
    print("All tests passed!");
  }

  





}

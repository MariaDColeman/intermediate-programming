//function declarations

// function to check whether the inputted text is valid (doesn't have something other than A,C,G,or T (upper or lower case) for a non-whitespace character and the number of A/C/G/T characters is not 0 and not greater than 15000
int invalidTextFileCheck(FILE *filehandleIN, int maxLength);

// function to check whether inserted character is valid (upper or lower case A,C,G, or T)
int invalidCharCheck(char c);

// assuming the text is valid, store in an array of characters
char[] createArrayFromFile(FILE *filehandleIN, int counter);

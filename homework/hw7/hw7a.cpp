/*
Maria Coleman
mcolem31
mcolem31@jhu.edu
600.120 S17
Homework 7
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include "fileIO.hpp"

using std::cout;
using std::endl;
//using std::srand((unsigned int) 5);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Error: Improper number of command line arguments" << endl;
		return 1;
	}
	else {
	string filename(argv[1]);
	char orderChar = *(argv[2]);

	fileIO partA;
	partA.parta(filename, orderChar);

	return 0;
	}
}

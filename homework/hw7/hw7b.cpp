/*
Maria Coleman
mcolem31
mcolem31@jhu.edu
600.120 S17
Homework 7
*/
#include <iostream>
#include <string>
#include "fileIO.hpp"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	if (argc != 3) {
		cout << "Error: Improper number of command line arguments" << endl;
		return 1;
	}
	else {
	string filename(argv[1]);
	char num = *(argv[2]);

	fileIO partB;
	partB.partb(filename, num);

	return 0;
	}
}
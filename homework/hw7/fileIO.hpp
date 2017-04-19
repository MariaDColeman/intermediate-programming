/*
Maria Coleman
mcolem31
mcolem31@jhu.edu
600.120 S17
Homework 7
*/
#ifndef FILEIO_H
#define FILEIO_H

#include<iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>


using std::string;
using std::map;
using std::vector;
using std::pair;


class fileIO {

public:

  fileIO () {}
  
	void parta(string, char);

  void abcd();
  
  void checkAndInsert(string, string, string);

	void putInMap(vector<string>::const_iterator, vector<string>::const_iterator);

	void optiona();

	void optionr();

	void optionc();

	void partb(string, int);

  friend class testA;
  friend class testB;
  
private:
	vector<string> textVector;
  vector<string> textVectorTemp;
  map<pair<string, string>, map<string, int>> totalMap;
  map<int, vector<string>> trigramsByFreq;
};











#endif




//PART A



//map<string, int> counters; //stores each trigram and associated count
//map<int, vector<string> > trigramsByFreq;

//map<int, string> trigramsByFreq;



//PART B


//pair <string, string> firstAndSec;
//map <string, int> thirdAndCount;



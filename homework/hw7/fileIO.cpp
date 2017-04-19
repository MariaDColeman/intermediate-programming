/*
Maria Coleman
mcolem31
mcolem31@jhu.edu
600.120 S17
Homework 7
*/

#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iterator>
#include <map>
#include "fileIO.hpp"





using std::cout;
using std::endl;
using std::ifstream;
using std::stringstream;
using std::srand;
using std::rand;




void checkAndInsert(string, string, string);
void optiona();
void optionr();
void optionc();
void putInMap(vector<string>::const_iterator, vector<string>::const_iterator);



//PART A
//let inputName be the name of the text file that was a command line argument containing the names of the actual text files with authors work.
//let orderChar be the character entered on how to order
void fileIO::parta(string file, char inputChar) {

    string inputName = file;
    string filename;
    string a;
    string b;
    string c;
    string d;
    string trigram;
    string word1;
    string word;
    char orderChar = inputChar;
    ifstream inputA (inputName);
    if (inputA.is_open()) {
        while (inputA >> filename) {

            ifstream inputA2 (filename);
            if (inputA2.is_open()) {
                while (inputA2 >> word) {

                    textVectorTemp.push_back(word);
                }

                for(vector<string>::const_iterator iter = textVectorTemp.begin(); iter != (textVectorTemp.end()-2); ++iter) {
                    putInMap(iter, iter+2);
                }

                abcd();
                inputA2.close();
            }

            else {
                cout << "Error: Cannot open " << filename << endl;
            }
        }
        inputA.close();




        switch (orderChar) {
        case 'a':
            optiona();
            break;
        case 'r':
            optionr();
            break;
        case 'c':
            optionc();
            break;
        default:
            cout << "Error: not proper argument letter. Must be a, r, or c" << endl;
            break;
        }

    }
    else {
        cout << "Unable to open command line text file" << endl;
    }

}

void fileIO::abcd() {

    string a;
    string b;
    string c;
    string d;

    a = *(textVectorTemp.begin());
    if (textVectorTemp.size() == 1) { //there is only one word in file

        checkAndInsert("<START_1>", "<START_2>", a);

        checkAndInsert("<START_2>", a, "<END_1>");

        checkAndInsert(a, "<END_1>", "<END_2>");
    }


    else {

        b = *((textVectorTemp.begin())+1);
        if (textVectorTemp.size() == 2) { //there is only two words in file

            checkAndInsert("<START_1>", "<START_2>", a);
            checkAndInsert("<START_2>", a, b);
            checkAndInsert(a, b, "<END_1>");
            checkAndInsert(b, "<END_1>", "<END_2>");

        }
        else {
            c = *((textVectorTemp.end())-2);
            if (textVectorTemp.size() == 3) { //there is only three words in file

                checkAndInsert("<START_1>", "<START_2>", a);
                checkAndInsert("<START_2>", a, b);
                checkAndInsert(b, c, "<END_1>");
                checkAndInsert(c, "<END_1>", "<END_2>");

            }
            else {
                d = *((textVectorTemp.end())-1);

                checkAndInsert("<START_1>", "<START_2>", a);
                checkAndInsert("<START_2>", a, b);
                checkAndInsert(c, d, "<END_1>");
                checkAndInsert(d, "<END_1>", "<END_2>");


            } //end of if not 3 words
        } //end of if not 2 words
    } //end of if not 1 word
    textVectorTemp.clear();
    textVectorTemp.shrink_to_fit();
}


void fileIO::checkAndInsert(string st1, string st2, string st3) {
    if (totalMap[make_pair(st1, st2)].count(st3)) {
        ++(totalMap[make_pair(st1, st2)][st3]);
    }
    else {
        totalMap[make_pair(st1, st2)][st3] = 1;
    }
}


void fileIO::putInMap(vector<string>::const_iterator start, vector<string>::const_iterator end) {
    pair <string, string> firstAndSec;
    while (start != end) {
        string first = *start;
        start++;
        string second = *start;
        //firstAndSec = make_pair(*start, *(++start));
        firstAndSec = make_pair(first, second);

        if(totalMap[firstAndSec].count(*(++start))) {
            ++(totalMap[firstAndSec][*start]);
        }
        else {
            totalMap[firstAndSec][*start] = 1;
        }


    }

}






void fileIO::optiona() {
    for(map<pair<string, string>, map<string, int>>::const_iterator it = totalMap.begin(); it != totalMap.end(); ++it) {
        for(map<string, int>::const_iterator it2 = (it->second).begin(); it2 != (it->second).end(); ++it2) {
            cout << it->first.first << " " << it->first.second << " " << it2->first << " " << it2->second << endl;
        }
    }

}

void fileIO::optionr() {
    for(map<pair<string, string>, map<string, int>>::const_reverse_iterator rit = totalMap.rbegin(); rit != totalMap.rend(); ++rit) {
        for(map<string, int>::const_reverse_iterator rit2 = (rit->second).rbegin(); rit2 != (rit->second).rend(); ++rit2) {
            cout << rit->first.first << " " << rit->first.second << " " << rit2->first << " " << rit2->second << endl;
        }
    }
}


void fileIO::optionc() {
    //make a map where the key is the frequency and what it maps to is the trigram as a string
    for(map<pair<string, string>, map<string, int>>::const_iterator itc = totalMap.begin(); itc != totalMap.end(); ++itc) {

        for(map<string, int>::const_iterator itc2 = (itc->second).begin(); itc2 != (itc->second).end(); ++itc2) {
            stringstream s;
            s << (itc->first.first) << " " << (itc->first.second) << " " << (itc2->first);
            string result = s.str();
            trigramsByFreq[itc2->second].push_back(result);
        }
    }

    //print out new map above
    for(map<int, vector<string>>::const_iterator iterP = trigramsByFreq.begin(); iterP != trigramsByFreq.end(); ++iterP) {

        for (vector<string>::const_iterator stri = iterP->second.begin(); stri != iterP->second.end(); ++stri) {
            cout << *stri << " " << iterP->first << endl;
        }
    }



}












//PART B
//let model be the string holding the name of the language model text file entered as a command line argument
void fileIO::partb(string fileb, int num) {

    srand(5);
    string word1;
    string word2;
    string word3;
    string model = fileb;
    int numTimes = num;


    int count;
    ifstream input (model);


    if (input.is_open()) {


        while((input >> word1) && (input >> word2) && (input >> word3) && (input >> count)) {

            totalMap[make_pair(word1, word2)][word3] = count;

        }


//randomly generated texts
        for (int i=0; i<numTimes; i++) { //generate text by the inputted number of times
            string str1 = "<START_1>";
            string str2 = "<START_2>";
            string temp;
            int denom = 0;
            cout << str1 << " " << str2;

            while (!((str1 == "<END_1>") && (str2 == "<END_2>"))) {

                denom = 0;

                map<pair<string, string>, map<string, int>>::const_iterator ito;
                ito = totalMap.find(make_pair(str1, str2));

                for(map<string, int>::const_iterator it = (ito->second).begin(); it != (ito->second).end(); ++it) {
                    denom += (it->second);


                }

                int cond = rand() % denom;



                int prev = 0;
                int boole = 1;


                ito = totalMap.find(make_pair(str1, str2));

                for (map<string, int>::const_iterator it = (ito->second).begin(); it != (ito->second).end(); ++it) {

                    if (boole && (cond >= prev) && (cond < ((it->second)+prev))) {
                        temp = str2;
                        str2 = it->first;
                        cout << " " << str2;
                        str1 = temp;
                        boole = 0;
                    }
                    prev += (it->second);

                }

            } // end of while loop

            cout << endl;
        }





        input.close();

    }

    else {
        cout << "Unable to open language model text file" << endl;
    }

} //end of part b

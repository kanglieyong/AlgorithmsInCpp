#ifndef HEADERS_H_
#define HEADERS_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

bool oneCharOff(const string& word1, const string& word2);

map<string, vector<string> > computeAdjacentWords1(const vector<string>& words);
map<string, vector<string> > computeAdjacentWords2(const vector<string>& words);
map<string, vector<string> > computeAdjacentWords3(const vector<string>& words);

void printHighChangeables(const map<string, vector<string>>& adjacentWords, int minWords);

#endif

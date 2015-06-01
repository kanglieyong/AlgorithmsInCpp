#include "headers.h"

map<string, vector<string> > computeAdjacentWords1(const vector<string>& words)
{
  map<string, vector<string> > adjWords;

  for (size_t i = 0; i < words.size(); i++) {
    for (size_t j = i; j < words.size(); j++) {
      if (oneCharOff(words[i], words[j])) {
	adjWords[words[i]].push_back(words[j]);
	adjWords[words[j]].push_back(words[i]);
      }
    }
  }

  return adjWords;
}

map<string, vector<string> > computeAdjacentWords2(const vector<string>& words)
{
  map<string, vector<string>> adjWords;
  map<int, vector<string> > wordsByLength;

  for (int i = 0; i < words.size(); i++) {
    wordsByLength[words[i].size()].push_back(words[i]);
  }

  map<int, vector<string> >::const_iterator itr;
  for (itr = wordsByLength.begin(); itr != wordsByLength.end(); ++itr) {
    const vector<string>& groupsWords = itr->second;
    for (int i = 0; i < groupsWords.size(); i++) {
      for (int j = i; j < groupsWords.size(); j++) {
	if ( oneCharOff(groupsWords[i], groupsWords[j]) ) {
	  adjWords[groupsWords[i]].push_back(groupsWords[j]);
	  adjWords[groupsWords[j]].push_back(groupsWords[i]);
	}
      }
    }
  }

  return adjWords;
}

map<string, vector<string> > computeAdjacentWords3(const vector<string>& words)
{
  map<string, vector<string> > adjWords;
  map<int, vector<string> > wordsByLength;

  for (int i = 0; i < words.size(); i++) wordsByLength[words[i].size()].push_back(words[i]);

  map<int, vector<string> >::const_iterator itr;
  for (itr = wordsByLength.begin(); itr != wordsByLength.end(); ++itr) {
    const vector<string>& groupsWords = itr->second;
    int                      groupNum = itr->first;

    for (int i = 0; i < groupNum; i++) {
      map<string, vector<string> > repToWords;

      for (int j = 0; j < groupsWords.size(); j++) {
	string rep = groupsWords[j];
	rep.erase(i, 1);
	repToWords[rep].push_back(groupsWords[j]);
      }
      
      map<string, vector<string> >::const_iterator itr2;
      for (itr2 = repToWords.begin(); itr2 != repToWords.end(); ++itr2) {
        const vector<string>& clique = itr2->second;
	if (clique.size() >= 2) {
	  for (int p = 0; p < clique.size(); p++) {
	    for (int q = p + 1; q < clique.size(); q++) {
	      adjWords[clique[p]].push_back(clique[q]);
	      adjWords[clique[q]].push_back(clique[p]);
	    }
	  }
	}
      }
    }
  }

  return adjWords;
}

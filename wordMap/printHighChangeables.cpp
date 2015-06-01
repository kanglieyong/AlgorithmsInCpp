#include "headers.h"

void printHighChangeables(const map<string, vector<string> >& adjacentWords, int minWords)
{
  map<string, vector<string> >::const_iterator itr;

  for (itr = adjacentWords.begin(); itr != adjacentWords.end(); ++itr) {
    const pair<string, vector<string> >& entry = *itr;
    const vector<string>&                words = entry.second;

    if (words.size() >= minWords) {
      cout << entry.first << " (" << words.size () << "): ";
      for (size_t i = 0; i < words.size(); i++) cout << " " << words[i];
      cout << endl;
    }
  }
}

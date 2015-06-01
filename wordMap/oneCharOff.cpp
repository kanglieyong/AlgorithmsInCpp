#include "headers.h"

bool oneCharOff(const string& word1, const string& word2)
{
  if (word1.size() != word2.size()) return false;

  int diffs = 0;
  for (size_t i  = 0; i < word1.size(); i++) {
    if (word1[i] != word2[i]) {
      if (++diffs > 1) return false;
    }
  }

  return diffs == 1;
}

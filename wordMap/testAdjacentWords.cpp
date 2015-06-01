#include "headers.h"
#include <algorithm>
#include <set>
#include <iterator>

using std::function;
using std::set;
using std::back_insert_iterator;

int main(void)
{
  vector<string> a({"helo", "hero", "five", "sive", "tive", "five", "gear", "geat", "gelo", "selo", "hero",  "sivt", "moet", "moto"});
  set<string> wordset(a.begin(), a.end());
  a.clear();
  copy(wordset.begin(), wordset.end(), back_insert_iterator<vector<string> >(a));

  map<string, vector<string> > b = computeAdjacentWords3(a);

  printHighChangeables(b, 2);

  return 0;
}

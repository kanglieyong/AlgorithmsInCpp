#include "hash.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string sn[5] = {"hello", "recurse", "aboundon", "zone", "toolkit"};

  int tableSize = 37;
  vector<string> aTable(tableSize);
  for (int i = 0; i < 5; i++) {
    aTable[hash3(sn[i], tableSize)] = sn[i];
  }

  for (int i = 0; i < aTable.size(); i++) {
    if ((i + 1) % 5 == 0) {
      cout << endl;
    }
    cout << i << ": " << aTable[i] << "\t";
  }

  cout << endl;

  return 0;
}

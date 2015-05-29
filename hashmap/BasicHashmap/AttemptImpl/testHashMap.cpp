#include "hashmap.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
  DefaultHash<int> a;
  cout << a.numBuckets() << endl;

  DefaultHash<string> b(113);
  cout << b.numBuckets() << endl;
  cout << b.hash("Hello") << endl;
  cout << b.hash("Hello") << endl;
  cout << b.hash("world!") << endl;

  cout <<"****************************" << endl;

  hashmap<int, int> myHash;
  myHash.insert(make_pair(4, 10));
  myHash.insert(make_pair(6, 15));

  cout << "***************************" << endl;

  cout << "operator[]" << endl;
  cout << myHash[6] << endl;
  cout << "Done!" << endl;

  cout << "***************************" << endl;

  myHash[6] = 12;
  myHash[6] = 34;
  cout << myHash[6] << endl;

  cout << "***************************" << endl;
  auto it = myHash.find(6);
  if (it != nullptr) cout << "the key 4 maps to " << it->second << endl;
  else               cout << "cannot find 4 in map" << endl;

  return 0;
}

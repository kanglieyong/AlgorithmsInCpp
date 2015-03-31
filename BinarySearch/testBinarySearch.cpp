#include "BinarySearch.h"
#include <iostream>
#include <vector>

int main()
{
  using std::cout;
  using std::endl;
  using std::vector;
  
  vector<int> aVec({2, 12, 31, 35, 55, 89, 111, 210, 291, 400});
  for (auto & x : aVec) {
    cout << x << " ";
  }
  cout << endl;

  int ta = binarySearch(aVec, 15);
  int tb = binarySearch(aVec, 35);
  int tc = binarySearch(aVec, 500);

  cout << "ta = " << ta << endl
       << "tb = " << tb << endl
       << "tc = " << tc << endl;

  return 0;
}

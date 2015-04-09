#include "BinaryHeap.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  vector<int> aVec({10, 3, 2, 11, 8, 7, 5, 1, 9, 6, 4, 12, 15, 13, 12});
  int t = 12;
  BinaryHeap<int> aBH(12);
  BinaryHeap<int> bBH(aVec);

  return 0;
}

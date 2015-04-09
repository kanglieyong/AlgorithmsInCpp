#include "BinaryHeap.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  vector<int> aVec({10, 3, 2, 11, 8, 7, 5, 1, 9, 6, 4, 12, 15, 13, 12});
  int t = 12;
  BinaryHeap<int> aBH(t);
  BinaryHeap<int> bBH(aVec);

  bool aIsEmpty = aBH.isEmpty();
  if (aIsEmpty) {
    cout << "aBH is empty!" << endl;
  }

  int tmpInt;
  while (!bBH.isEmpty()) {
    bBH.deleteMin(tmpInt);
    cout << tmpInt << " ";
  }
  cout << endl;

  vector<int> cVec({4, 12, 3, 8, 7, 9, 5, 14, 1, 6, 10, 2});
  BinaryHeap<int> cBH(cVec);
  cBH.makeEmpty();
  bool cIsEmpty = cBH.isEmpty();
  if (cIsEmpty) {
    cout << "cBH is empty!" << endl;
  }

  vector<int> dVec({3, 4, 2, 1, 5});
  BinaryHeap<int> dBH(dVec);
  BinaryHeap<int> eBH(dBH);

  int eInt;
  while (!eBH.isEmpty()) {
    eBH.deleteMin(eInt);
    cout << eInt << " ";
  }
  cout << endl;

  vector<int> fVec({6, 4, 8, 3, 5, 1, 9, 2});
  BinaryHeap<int> fBH(fVec);
  dBH = fBH;
  cout << dBH.size() << endl;
  
  return 0;
}

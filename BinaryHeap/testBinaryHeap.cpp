#include "BinaryHeap.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int t = 12;
  BinaryHeap<int> aBH(t);
  bool aIsEmpty = aBH.isEmpty();
  if (aIsEmpty) {
    cout << "aBH is empty!" << endl;
  }

  int tmpInt;
  vector<int> bVec({10, 3, 2, 11, 8, 7, 5, 1, 9, 6, 4, 12, 15, 13, 12});  
  BinaryHeap<int> bBH(bVec);
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

  vector<int> fVec({16, 14, 18, 13, 15, 11, 19, 12});
  BinaryHeap<int> fBH(fVec);
  dBH = fBH;
  int whatFirst = dBH.findMin();
  cout << whatFirst << endl;

  BinaryHeap<int> gBH(10);
  if (gBH.isEmpty()) {
    cout << "gBH is empty! " << endl;
  }
  gBH.deleteMin();
  
  return 0;
}

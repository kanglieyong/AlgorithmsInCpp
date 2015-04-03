#include "Vector.h"
#include <iostream>

using std::cout;
using std::endl;

void copyAndDisplay(Vector<int>& theVec, int arr[], int size)
{
  for (int i = 0; i < size; i++) {
    theVec.push_back(arr[i]);
  }

  cout << "The elements in the vector is now : " << endl;
  for (int i = 0; i < theVec.size(); i++) {
    cout << theVec[i] << " ";
  }
  cout << endl;
}

void showSizeAndCapacity(const Vector<int>& theVec)
{
  cout << "It's size is :     " << theVec.size() << endl;
  cout << "It's capacity is : " << theVec.capacity() << endl;
}

int main()
{
  Vector<int> aVec;
  int arr[10] = {23, 10, 3, 21, 31, 89, 7, 34, 8, 9};
  copyAndDisplay(aVec, arr, 10);

  if (!aVec.empty()) {
    cout << "aVec is not empty!" << endl;
  }

  showSizeAndCapacity(aVec);
  
  int t = 100;
  aVec.push_back(t);
  showSizeAndCapacity(aVec);  

  while (aVec.size()) {
    cout << aVec.back() << " ";
    aVec.pop_back();
  }
  cout << endl;

  copyAndDisplay(aVec, arr, 10);
  aVec.resize(30);
  showSizeAndCapacity(aVec);

  for (Vector<int>::const_iterator it = aVec.begin(); it != aVec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  aVec.resize(14);
  showSizeAndCapacity(aVec);
  for (Vector<int>::const_iterator it = aVec.begin(); it != aVec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  
  int numElement = 31;
  for (Vector<int>::iterator it = aVec.begin(); it != aVec.end(); it++) {
    if (*it == numElement) {
      cout << "plus match element with 10: " << endl;
      *it += 10;
      cout << "Now match element is : " << *it << endl;
    }
  }
  cout << endl;

  for (Vector<int>::const_iterator it = aVec.begin(); it != aVec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
  
  return 0;
}

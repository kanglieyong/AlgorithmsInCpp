#include "insertionSort.h"
#include <iostream>

int main()
{
  using std::cout;
  using std::endl;
  
  vector<int> a({10, 5, 4, 9, 2, 3, 8, 1, 7, 6});
  insertionSort(a);
  for (auto & x : a) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}

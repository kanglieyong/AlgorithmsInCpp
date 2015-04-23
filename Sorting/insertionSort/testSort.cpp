/* Thu Apr 23 22:55:37 CST 2015 */

#include "insertionSort.h"
#include <iostream>

// void insertionSort(vector<Comparable>& a);
// void insertionSort2(vector<Comparable>& a, int left, int right);

int main()
{
  using std::cout;
  using std::endl;
  
  vector<int> a({10, 5, 4, 9, 2, 3, 8, 1, 7, 6});
  insertionSort2(a, 0, a.size() - 1);
  for (auto & x : a) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}

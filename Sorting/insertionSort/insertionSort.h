/*
 * Simple insertion sort.
 */
#include <vector>
using std::vector;

template <typename Comparable>
void insertionSort(vector<Comparable>& a)
{
  int j;

  for (int p = 1; p < a.size(); p++) {
    Comparable tmp = a[p];
    for (j = p; j > 0 && tmp < a[j - 1]; j--) {
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}

template <typename Comparable>
void insertionSort2(vector<Comparable>& a, int left, int right)
{
  int j;

  for (int p = 1; p < right - left + 1; p++) {
    Comparable tmp = a[left + p];
    for (j = left + p; j > left && tmp < a[j - 1]; j--) a[j] = a[j - 1];
    a[j] = tmp;
  }
}

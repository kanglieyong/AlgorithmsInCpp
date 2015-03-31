#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#define NOT_FOUND -1
#include <vector>
using std::vector;

template <typename Comparable>
int binarySearch(const vector<Comparable>& a, const Comparable& x)
{
  int low = 0, high = a.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (x < a[mid]) {
      high = mid - 1;
    } else if (a[mid] < x) {
      low = mid + 1;
    } else {
      return mid;  // Found
    }
  }

  return NOT_FOUND;
}

#endif

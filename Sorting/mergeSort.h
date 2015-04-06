#include <vector>
using std::vector;

template <typename Comparable>
void mergeSort(vector<Comparable>& a)
{
  vector<Comparable> tmpArray(a.size());
  mergetSort(a, tmpArray, 0, a.size() - 1);
}

template <typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right)
{
  if (left < right) {
    int center = (left + right) / 2;
    mergeSort(a, tmpArray, left, center);
    mergeSort(a, tmpArray, center + 1, right);
    merge(a, tmpArray, left, center + 1, right);
  }
}

template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd)
{
  int leftEnd = rightPos - 1;
  int tmpPos = leftPos;
  int numElement = rightEnd - leftPos + 1;

  while (leftPos <= leftEnd && rightPos <= rightEnd) {
    if (a[leftPos] < a[rightPos]) {
      tmpArray[tmpPos++] = a[leftPos++];
    } else {
      tmpArray[tmpPos++] = a[rightPos++];
    }
  }

  while (leftPos <=)
}

#include <vector>

using std::vector;

// Declarition
template <typename Comparable>
void swap(Comparable& a, Comparable& b);

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right);

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right);

template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right);

// Definition
template <typename Comparable>
void quickSort(vector<Comparable>& a)
{
  quickSort(a, 0, a.size() - 1);
}

template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right)
{
  if (left + 10 <= right) {
    Comparable pivot = median3(a, left, right);

    // Begin partioning
    int i = left, j = right - 1;
    for (; ; ) {
      while (a[++i] < pivot) {}
      while (pivot < a[--j]) {}
      if (i < j) swap(a[i], a[j]);
      else break;
    }

    swap(a[i], a[right - 1]);    // Restore pivot

    quickSort(a, left, i - 1);   // Sort small elements
    quickSort(a, i + 1, right);  // Sort large elements
  }
  // Do an insertion sort on the subarray
  else {
    insertionSort(a, left, right);

    int i = left + 1, j = right - 2;
    for (; ; ) {
      while (a[i] < pivot) i++;
      while (pivot < a[j]) j--;
      if (i < j) swap(a[i], a[j]);
      else break;
    }
  }
}

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right)
{
  int center = (left + right) / 2;
  if (a[center] < a[left] )   swap(a[left],   a[center]);
  if (a[right]  < a[left] )   swap(a[left],   a[right]);
  if (a[right]  < a[center] ) swap(a[center], a[right]);

  // Place pivot at position right - 1
  swap(a[center], a[right - 1]);
  return a[right - 1];
}

template <typename Comparable>
void swap(Comparable& a, Comparable& b)
{
  Comparable& tmp = a;
  a = b;
  b = tmp;
}
/*
 * Simple insertion sort.
 */

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right)
{
  int j;

  for (int p = 1; p < right - left; p++) {
    Comparable tmp = a[left + p];
    for (j = left + p; j > left && tmp < a[j - 1]; j--) {
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}

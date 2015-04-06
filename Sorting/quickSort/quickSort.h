#include <vector>

using std::vector;

// declarition
void swap(Comparable& a, Comparable& b);


template <typename Comparable>
void quickSort(vector<Comparable>& a)
{
  quickSort(a, 0, a.size() - 1);
}

template <typename Comparable>
const Comparable& median3(vector<Comparable>& a, int left, int right)
{
  int center = (left + right) / 2;
  if (a[center] < a[left]) swap(a[left], a[center]);
}

template <typename Comparable>
void swap(Comparable& a, Comparable& b)
{
  Comparable& tmp;
  tmp = a;
  a = b;
  b = tmp;
}

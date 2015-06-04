#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <vector>
#include <stdexcept>

using std::vector;
using std::underflow_error;
using std::overflow_error;

template <typename Comparable>
class BinaryHeap
{
public:
  explicit BinaryHeap(int capacity = 100);
  explicit BinaryHeap(const vector<Comparable>& items);

  bool isEmpty() const { return currentSize == 0; }
  const Comparable& findMin() const
  {
    if (isEmpty()) {
      throw overflow_error("Empty");
    }
    return array[1];
  }

  void insert(const Comparable& x);
  void deleteMin();
  void deleteMin(Comparable& minItem);
  void makeEmpty();

private:
  int currentSize;  // Number of elements in heap
  vector<Comparable> array;

  void buildHeap();
  void percolateDown(int hole);
};

#endif

// public methods

// constructor
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
  : currentSize(0),
    array(capacity + 1)
{  
}

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable>& items)
  : currentSize(items.size()),
    array(items.size() + 10)
{
  for (int i = 0; i < items.size(); i++) {
    array[i + 1] = items[i];
  }
  buildHeap();
}

// Insert item x, allowing duplicates.

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable& x)
{
  if (currentSize == array.size() - 1) {
    array.resize(array.size() * 2);
  }

  // percolate up
  int hole = ++currentSize;
  for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
    array[hole] = array[hole / 2];
  }
  array[hole] = x;
}

// Remove the minimum item.
// Throws UnderflowException if empty.

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
  if (isEmpty()) {
    throw underflow_error("underflow_error");
  }

  array[1] = array[currentSize--];
  percolateDown(1);
}

// Remove the minimum item and place it to the minItem
// Throws UnderflowException if empty.

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable& minItem)
{
  if (isEmpty()) {
    throw underflow_error("underflow_error");
  }

  minItem = array[1];
  array[1] = array[currentSize--];
  percolateDown(1);
}

template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
  array.clear();
  currentSize = 0;
}

// private methods

// Internal method to percolate down in the heap.
// hole is the index at which the percolate begins.

template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
  int child;
  Comparable tmp = array[hole];

  for (; hole * 2 <= currentSize; hole = child) {
    child = hole * 2;
    if (child != currentSize && array[child + 1] < array[child]) {
      child++;
    }
    if (array[child] < tmp) {
      array[hole] = array[child];
    } else {
      break;  // Get it!
    }
  }
  array[hole] = tmp;
}

// Establish heap order property from an arbitrary
// arrangement of items. Runs in linear time.

template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
  for (int i = currentSize / 2; i > 0; i--) {
    percolateDown(i);
  }
}

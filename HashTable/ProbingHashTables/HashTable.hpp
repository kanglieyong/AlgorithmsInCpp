#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include "Prime.hpp"
#include <vector>

using std::vector;

template <typename HashedObj>
class HashTable
{
public:
  explicit HashTable(int size = 101);

  bool contains(const HashedObj& x) const;

  void makeEmpty();
  bool insert(const HashedObj& x);
  bool remove(const HashedObj& x);
  
  enum EntryType { ACTIVE, EMPTY, DELETED };
  
private:
  struct HashEntry
  {
    HashedObj element;
    EntryType info;

    HashEntry(const HashedObj& e = HashedObj(), EntryType i = EMPTY)
      : element(e), info(i) {}
  };

  vector<HashEntry> array;
  int currentSize;

  bool isActive(int currentPos) const;
  int findPos(const HashedObj& x) const;
  void rehash();
  int myhash(const HashedObj& x) const;
};

#endif

// public methods

// constructor
template <typename HashedObj>
HashTable<HashedObj>::HashTable(int size)
  : array(nextPrime(size))
{
  makeEmpty();
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
  currentSize = 0;
  for (int i = 0; i < array.size(); i++) {
    array[i].info = EMPTY;
  }
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& x) const
{
  return isActive(findPos(x));
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& x)
{
  int currentPos = findPos(x);
  if (isActive(currentPos)) return false;

  array[currentPos] = HashEntry(x, ACTIVE);

  if (++currentSize > array.size() / 2) rehash();

  return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& x)
{
  int currentPos = findPos(x);
  if (!isActive(currentPos)) return false;

  array[currentPos].info = DELETED;

  return true;
}

// private methods

template <typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
  return array[currentPos].info == ACTIVE;
}

template <typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj& x) const
{
  int offset = 1;
  int currentPos = myhash(x);

  while (array[currentPos].info != EMPTY && array[currentPos].element != x) {
    currentPos += offset;
    offset += 2;
    if (currentPos >= array.size()) {
      currentPos -= array.size();
    }
  }

  return currentPos;
}

template <typename HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj& x) const
{
  int hashVal = x.hashCode();
  hashVal %= array.size();
  if (hashVal < 0) hashVal += array.size();

  return hashVal;
}

template <typename HashedObj>
void HashTable<HashedObj>::rehash()
{
  vector<HashEntry> oldArray = array;
  array.resize(nextPrime(2 * oldArray.size()));
  for (int i = 0; i < array.size(); i++) array[i].info = EMPTY;

  currentSize = 0;
  for (int i = 0; i < oldArray.size(); i++) {
    if (oldArray[i].info == ACTIVE) {
      insert(oldArray[i].element);
    }
  }
}

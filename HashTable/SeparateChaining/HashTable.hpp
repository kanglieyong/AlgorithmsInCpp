#include "Prime.hpp"

#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;
using std::function;

template <typename HashedObj>
class HashTable
{
public:
  explicit HashTable(int size = 101)
    : theLists(size) {}

  bool contains(const HashedObj& x) const;

  void makeEmpty();
  bool insert(const HashedObj& x);
  bool remove(const HashedObj& x);
  
private:
  vector<list<HashedObj> > theLists;
  int currentSize;

  int myhash(const HashedObj& x) const;
  void rehash();
};

// private methods
template <typename HashedObj>
int HashTable<HashedObj>::myhash(const HashedObj& x) const
{
  int hashVal = x.hashCode();

  hashVal %= theLists.size();
  if (hashVal < 0) hashVal += theLists.size();

  return hashVal;
}

template <typename HashedObj>
void HashTable<HashedObj>::rehash()
{
  vector<list<HashedObj> > oldLists = theLists;

  theLists.resize(nextPrime(2 * theLists.size()));
  for (int j = 0; j < theLists.size(); j++) {
    theLists[j].clear();
  }
  currentSize = 0;

  for (int i = 0; i < oldLists.size(); i++) {
    // list<HashedObj>::iterator iter = oldLists[i].begin();
    auto iter = oldLists[i].begin();
    while (iter != oldLists[i].end()) {
      insert(*iter++);
    }
  }
}

// public methods
template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
  for (int i = 0; i < theLists.size(); i++) {
    theLists[i].clear();
  }
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& x) const
{
  const list<HashedObj>& whichList = theLists[myhash(x)];

  return find(whichList.begin(), whichList.end(), x) != whichList.end();
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& x)
{
  list<HashedObj>& whichList = theLists[myhash(x)];
  if (find(whichList.begin(), whichList.end(), x) != whichList.end()) return false;

  whichList.push_back(x);

  if (++currentSize > theLists.size()) {
    rehash();
  }

  return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& x)
{
  list<HashedObj>& whichList = theLists[myhash(x)];
  // list<HashedObj>::iterator iter = find(whichList.begin(), whichList.end(), x);
  auto iter = find(whichList.begin(), whichList.end(), x);

  if (iter == whichList.end()) return false;

  whichList.erase(iter);
  --currentSize;

  return true;
}

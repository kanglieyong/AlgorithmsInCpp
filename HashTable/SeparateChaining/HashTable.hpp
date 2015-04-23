#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::string;
using std::vector;
using std::list;
using std::function;

template <typename HashedObj>
class HashTable
{
public:
  explicit HashTable(int size = 101);

  bool contains(const HashedObj& x) const;

  void makeEmpty();
  bool insert(const HashedObj& x);
  bool remove(const HashedObj& x);

private:
  vector<list<HashedObj> > theLists;
  int currentSize;

  void rehash();
  int myhash(const HashedObj& x) const;
};

int hash(const string& key)
{
  //
}

int hash(int key);

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
  for (int i = 0; i < theLists.size(); i++) theLists.clear();
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& x) const
{
  const list<HashedObj>& whichList = theLists[myhash(x)];
  return find(whichList.begin(), whichList.end(), x) != whichList.end();
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& x)
{
  list<HashedObj>& whichList = theLists[myhash(x)];
  list<HashedObj>::iterator iter = find(whichList.begin(), whichList.end(), x);

  if (iter == whichList.end()) return false;

  whichList.erase(iter);
  --currentSize;

  return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& x)
{
  list<HashedObj>& whichList = theLists[myhash(x)];
  if (find(whichList.begin(), whichList.end(), x) == whichList.end()) return false;

  whichList.push_back(x);

  if (++currentSize > theLists.size()) rehash();

  return true;
}

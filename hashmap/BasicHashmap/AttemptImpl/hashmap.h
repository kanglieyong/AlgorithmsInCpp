#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <list>

#include <iostream>
using std::cout;
using std::endl;

using std::invalid_argument;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;
using std::list;

template <typename T>
class DefaultHash
{
 public:
  DefaultHash(size_t numBuckets = 101) throw (invalid_argument);

  size_t hash(const T& key) const;
  size_t numBuckets() const { return mNumBuckets; }
  
 protected:
  size_t mNumBuckets;
};

template <>
class DefaultHash<string>
{
 public:
  DefaultHash(size_t numBuckets = 101) throw (invalid_argument);

  size_t hash(const string& key) const;
  size_t numBuckets() const { return mNumBuckets; }

 protected:
  size_t mNumBuckets;
};

template <typename Key, typename T, typename Compare = std::equal_to<Key>, typename Hash = DefaultHash<Key> >
class hashmap
{
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef pair<const Key, T> value_type;

  explicit hashmap(const Compare& comp = Compare(), const Hash& hash = Hash()) throw (invalid_argument);
  ~hashmap();

  hashmap(const hashmap<Key, T, Compare, Hash>& src);
  hashmap(hashmap<Key, T, Compare, Hash>&& src);
  hashmap<Key, T, Compare, Hash>& operator=(const hashmap<Key, T, Compare, Hash>& rhs);
  hashmap<Key, T, Compare, Hash>& operator=(hashmap<Key, T, Compare, Hash>&& rhs);

  void insert(const value_type& x);
  void erase(const key_type& x);
  value_type* find(const key_type& x);
  T& operator[](const key_type& x);

 protected:
  typedef list<value_type> ListType;

  vector<ListType>* mElems;
  size_t mSize;
  Compare mComp;
  Hash mHash;

 typename list<value_type>::iterator findElement(const key_type& x, size_t& bucket) const;
};
















#include "hashmap.cpp"

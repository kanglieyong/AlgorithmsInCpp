#include <stdexcept>
using namespace std;

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

#include "hashmap.cpp"

template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets) throw (invalid_argument)
{
	if (numBuckets <= 0) {
		throw invalid_argument("numBuckets must be > 0");
	}
	mNumBuckets = numBuckets;
}

template <typename T>
size_t DefaultHash<T>::hash(const T& key) const
{
	size_t bytes = sizeof(key);
	size_t res = 0;
	for (size_t i = 0; i < bytes; ++i) {
		unsigned char b = *((unsigned char*)&key + i);
		res += b;
	}
	return (res % mNumBuckets);
}

DefaultHash<string>::DefaultHash(size_t numBuckets) throw (invalid_argument)
{
	if (numBuckets <= 0) {
		throw invalid_argument("numBuckets must be > 0");
	}
	mNumBuckets = numBuckets;
}

size_t DefaultHash<string>::hash(const string& key) const
{
	size_t sum = 0;
	for (size_t i = 0; i < key.size(); i++) {
		sum += (unsigned char)key[i];
	}
	return (sum % mNumBuckets);
}

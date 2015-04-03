#ifndef VECTOR_H_
#define VECTOR_H_

template <typename Object>
class Vector
{
 public:
  explicit Vector(int initSize = 0)
    : theSize(initSize), theCapacity(initSize + SPACE_CAPACITY)
    {
      objects = new Object[theCapacity];
    }
  Vector(const Vector& src)
    : objects(0)
    {
      operator=(src);
    }
  ~Vector()
    {
      delete [] objects;
    }

  const Vector& operator=(const Vector& rhs)
    {
      if (this != &rhs) {
	delete [] objects;
	theSize = rhs.theSize;
	theCapacity = rhs.theCapacity;

	objects = new Object[theCapacity];
	for (int i = 0; i < theSize; i++) {
	  objects[i] = rhs.objects[i];
	}
      }
      return *this;
    }

  void resize(int newSize)
  {
    if (newSize > theCapacity) {
      reserve(newSize * 2 + 1);
    }
    theSize = newSize;
  }

  void reserve(int newCapacity)
  {
    if (newCapacity < theSize) {
      return;
    }

    Object* oldArray = objects;

    objects = new Object[newCapacity];
    for (int i = 0; i < theSize; i++) {
      objects[i] = oldArray[i];
    }

    theCapacity = newCapacity;

    delete [] oldArray;
  }

  Object& operator[](int index)
    {
      return objects[index];
    }
  const Object& operator[](int index) const
  {
    return objects[index];
  }

  bool empty() const
  {
    return theSize == 0;
  }

  int size() const
  {
    return theSize;
  }

  int capacity() const
  {
    return theCapacity;
  }

  void push_back(const Object& x)
  {
    if (theSize == theCapacity) {
      reserve(2 * theCapacity + 1);
    }
    objects[theSize++] = x;
  }

  void pop_back()
  {
    theSize--;
  }

  const Object& back() const
  {
    return objects[theSize - 1];
  }

  typedef Object* iterator;
  typedef const Object* const_iterator;

  iterator begin()
  {
    return &objects[0];
  }

  const_iterator begin() const
  {
    return &objects[0];
  }

  iterator end()
  {
    return &objects[size()];
  }

  const_iterator end() const
  {
    return &objects[size()];
  }

  enum { SPACE_CAPACITY = 16 };

 private:
  int theSize;
  int theCapacity;
  Object* objects;
};

#endif

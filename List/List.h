template <typename Object>
class List
{
 private:
  struct Node {
    Object data;
    Node* prev;
    Node* next;

    Node(const Object& d = Object(), Node* p = NULL, Node* n = NULL)
    : data(d), prev(p), next(n) {}
  };

 public:
  class const_iterator
  {
  public:
    const_iterator()
      : current(NULL)
      {}
    const Object& operator*() const
    {
      return retrieve();
    }

  protected:
    Node* current;

    Object& retrieve() const
      {
	return current->data;
      }

    const_iterator(Node* p)
      : current(p)
    {}

    friend class List<Object>;
  };

  class iterator : public const_iterator
  {
    //
  };

 public:
  List()
    {
      //
    }

  ~List()
    {
      //
    }
  const List& operator=(const List& rhs)
    {
      //
    }

  iterator begin()
  {
    //
  }

  const_iterator begin() const
  {
    //
  }

  iterator end()
  {
    //
  }

  const_iterator end() const
  {
    //
  }

  int size() const { return theSize; }
  bool empty() const { return size() == 0; }
  void clear() { while (!empty()) pop_front(); }

  Object& front() { return *begin(); }
  const Object& front() const { return *begin(); }
  Object& back() { return *--end(); }
  const Object& back() const { return *--end(); }

  void push_front(const Object& x) { insert(begin(), x); }
  void push_back(const Object& x) { insert(end(), x); }

  void pop_front() { erase(begin()); }
  void pop_back() { erase(--end()); }

  iterator insert(iterator itr, const Object& x)
  {
    //
  }
  
  iterator erase(iterator itr)
  {
    //
  }
  iterator erase(iterator iter, iterator end)
  {
    //
  }

 private:
  int theSize;
  Node* head;
  Node* tail;

  void init()
  {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
  }
};

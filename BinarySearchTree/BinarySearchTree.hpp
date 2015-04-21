#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

template <typename Comparable>
class BinarySearchTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree& src);
  ~BinarySearchTree();

  const Comparable& findMin() const;
  const Comparable& findMax() const;
  bool contains(const Comparable& x) const;
  bool isEmpty() const;
  void traverseTree(ostream& out = std::cout) const;

  void makeEmpty();
  void insert(const Comparable& x);
  void remove(const Comparable& x);

  const BinarySearchTree& operator=(const BinarySearchTree& rhs);

private:
  struct BinaryNode {
    Comparable element;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
      : element(theElement), left(lt), right(rt) {}
  };

  BinaryNode* root;

  void insert(const Comparable& x, BinaryNode* &t)
  {
    if (t == NULL) t = new BinaryNode(x, NULL, NULL);
    else if (x < t->element) insert(x, t->left);
    else if (x > t->element) insert(x, t->right);
    else ;
  }
  
  void remove(const Comparable& x, BinaryNode* &t)
  {
    if (t == NULL) return;

    if (x < t->element) {
      remove(x, t->left);
    } else if (x > t->element) {
      remove(x, t->right);
    } else if (t->left != NULL && t->right != NULL) {
      t->element = findMin(t->right)->element;
      remove(t->element, t->right);
    } else {
      BinaryNode* oldNode = t;
      t = (t->left != NULL) ? t->left : t->right;
      delete oldNode;
    }
  }

  BinaryNode* findMin(BinaryNode* t) const
  {
    if (t == NULL) return NULL;
    
    if (t->left == NULL) return t;

    return findMin(t->left);
  }
  
  BinaryNode* findMax(BinaryNode* t) const
  {
    if (t != NULL) {
      while (t->right != NULL) t = t->right;
    }

    return t;
  }
  
  bool contains(const Comparable& x, BinaryNode* t) const
  {
    if (t == NULL) return false;
    
    if (x < t->element) return contains(x, t->left);
    else if (x > t->element) return contains(x, t->right);
    else return true;
  }
  
  void makeEmpty(BinaryNode* &t)
  {
    if (t != NULL) {
      makeEmpty(t->left);
      makeEmpty(t->right);
      delete t;
    }
    t = NULL;
  }
  
  void traverseTree(BinaryNode* t, ostream& out = std::cout) const
  {
    if (t != NULL) {
      traverseTree(t->left, out);
      out << t->element << endl;
      traverseTree(t->right, out);
    }
  }
  
  BinaryNode* clone(BinaryNode* t) const
  {
    if (t == NULL) return NULL;

    return new BinaryNode(t->element, clone(t->left), clone(t->right));
  }
};


// implementations
// constructors and destructors

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree()
{
  root = NULL;
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree<Comparable>& src)
{
  root = clone(src.root);
}


template <typename Comparable>
const BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree<Comparable>& rhs)
{
  if (this != &rhs) {
    makeEmpty();
    root = clone(rhs.root);
  }
  return *this;
}

// destructor
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree()
{
  makeEmpty();
  root = NULL;
}

// read function
template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const
{
  return root == NULL;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin() const
{
  findMin(root)->element;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() const
{
  findMax(root)->element;
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const
{
  return contains(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::traverseTree(ostream& out) const
{
  traverseTree(root, out);
}

// write function
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x)
{
  insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x)
{
  remove(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty()
{
  makeEmpty(root);
}

#endif

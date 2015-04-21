#include "BinarySearchTree.hpp"
#include <string>
using std::string;

int main()
{
  BinarySearchTree<int> a;
  int ele1 = 10;
  int ele2 = 12;
  int ele3 = 8;
  int ele4 = 15;
  int ele5 = 5;
  int ele6 = 1;

  a.insert(ele1);
  a.insert(ele2);
  a.insert(ele3);
  a.insert(ele4);
  a.insert(ele5);
  a.insert(ele6);

  a.traverseTree();

  cout << endl;

  a.remove(ele4);
  a.traverseTree();

  cout << endl;

  BinarySearchTree<string> b;
  b.insert("haha");
  b.insert("celebrate");
  b.insert("define");
  b.insert("zone");
  b.insert("god");
  b.traverseTree();

  cout << endl;

  while (!b.isEmpty()) {
    string test = b.findMin();
    cout << "Min item: " << test << endl;
    b.remove(test);
  }

  return 0;
}

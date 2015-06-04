#include "HashTable.hpp"
#include "Employee.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Employee a;
  Employee k("kang");
  Employee w("lie2");
  Employee y("lie");
  Employee h("hu");
  
  HashTable<Employee> e;

  e.insert(a);
  e.insert(k);
  e.insert(w);
  e.insert(y);
  e.insert(h);

  bool success = e.remove(y);
  cout << success << endl;

  /* test contains */
  bool isIn = e.contains(w);
  cout << isIn << endl;

  return 0;
}

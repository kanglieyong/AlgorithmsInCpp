#include "List.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
  cout << "Now begin the List." << endl;
  List<string> a;

  string s1("Hello World!");
  string s2("Goodbye World!");
  string st("Yes it is!");
  string s3("Dennis Ritchie");
  a.push_back(s1);
  a.push_back(s2);
  a.push_back(st);
  a.push_back(s3);

  string s;
  int num = 0;

  cout << "size = " << a.size() << endl;
  for (List<string>::const_iterator itr = a.begin(); itr != a.end(); ++itr) {
      cout << "[" << num++ << "] " << *itr << endl;
  }
  cout << endl;

  for (List<string>::iterator itr = a.begin(); itr != a.end(); ++itr) {
      if (*itr == st) {
          a.erase(itr);
      }
  }
  cout << "After Erase: \n" << endl;

  num = 0;
  for (List<string>::const_iterator itr = a.begin(); itr != a.end(); ++itr) {
    cout << "[" << num++ << "] " << *itr << endl;
  }
  cout << endl;
  num = 0;
  while (!a.empty()) {
      s = a.front();
      cout << "[" << num++ << "] " << s << endl;
      a.pop_front();
  }
  cout << endl;

  cout << "Now end the List." << endl;
  cout << "Now size = " << a.size() << endl;
  
  return 0;
}

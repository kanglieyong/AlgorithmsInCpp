#include "gcd.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int maxNum = 60, minNum = 24;
  int gcdNum = gcd(maxNum, minNum);
  cout << gcdNum << endl;

  return 0;
}

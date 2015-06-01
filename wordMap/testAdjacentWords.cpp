#include "headers.h"

int main(void)
{
  vector<string> a({"helo", "hero", "five", "sive", "tive", "gear", "geat", "gelo", "selo", "sivt", "moet", "moto"});
  map<string, vector<string> > b = computeAdjacentWords3(a);

  printHighChangeables(b, 2);

  return 0;
}

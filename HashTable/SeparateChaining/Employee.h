#include <string>

using std::string;

class Employee
{
public:
  Employee(string inName, double inSalary, int inSeniority)
   : name(inName), salary(inSalary), seniority(inSeniority) {}

  const string& getName() const { return name; }

  bool operator==(const Employee& rhs) const { return getName() == rhs.getName(); }
  bool operator!=(const Employee& rhs) const { return !(*this == rhs); }

private:
  string name;
  double salary;
  int seniority;
};

int hash(const Employee& item)
{
  return hash(item.getName());
}

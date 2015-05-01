#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>

using std::string;

class Employee
{
public:
  Employee()
    : name("none") {}
  explicit Employee(const string& inName)
    : name(inName) {}

  const string& getName() const
  {
    return name;
  }

  bool operator==(const Employee& rhs) const
  {
    return getName() == rhs.getName();
  }

  bool operator!=(const Employee& rhs) const
  {
    return !(*this == rhs);
  }

  // public interfaces
  int hashCode() const;

private:
  string name;
  double salary;
  int seniority;
};

int Employee::hashCode() const
{
  int hashcode = 0;
  const string key = getName();

  for (int i = 0; i < key.length(); i++) {
    hashcode = hashcode * 37 + key[i];
  }

  return hashcode;
}

#endif

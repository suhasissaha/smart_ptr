#include <iostream>
#include <memory>
#include <string>

#define print(label, data) {std::cout << label << data << std::endl;}
struct Person
{
  Person(std::string name, int age) : _name(name), _age(age) {}
  ~Person() {std::cout << _name << " died at " << _age << std::endl;}
  int _age;
  std::string _name;
};

int main(int argc, char const *argv[])
{
  std::cout << std::boolalpha << std::endl;

  // init
  std::shared_ptr<Person> shp1 = std::make_shared<Person>("Ashok", 55);
  print("shp1.use_coutn() before using weak_ptr = ", shp1.use_count());
  std::weak_ptr<Person> wkp1(shp1);
  print("shp1.use_coutn() after using weak_ptr = ", shp1.use_count());
  
  // get
  // Person *p1 = wkp1.get(); // not allowed

  // expired
  print("wkp1.expired() ", wkp1.expired());
  shp1.reset();
  print("wkp1.expired() ", wkp1.expired());



  return 0;
}

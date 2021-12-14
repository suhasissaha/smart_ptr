#include <iostream>
#include <memory>
#include <string>
#include <utility>

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
  std::shared_ptr<Person> p1(new Person("Ashok", 61));
  print("1) p1.unique() ", p1.unique());
  std::shared_ptr<Person> p2 = std::make_shared<Person>("Sam", 42);

  // sharing
  std::shared_ptr<Person> p3 = p1;
  print("2) p1.unique() ", p1.unique());
  print("p1.get() ", p1.get());
  print("p3.get() ", p3.get());
  print("p3.use_count() ", p3.use_count());  

  {
    std::shared_ptr<Person> p4(std::move(p3));
    print("p3.get() ", p3.get());
    print("p4.get() ", p4.get());
    print("p4.use_count() ", p4.use_count());  
  }

  {
    std::shared_ptr<Person> p5 = p1;
    print("p5.use_count() ", p5.use_count());
  }
  print("p1.use_count() ", p1.use_count());

  return 0;
}

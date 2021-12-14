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

//void foo(std::unique_ptr<Person> iPtr) // pass by value not allowed -> copy
void foo(std::unique_ptr<Person>& iPtr)
{
  std::cout << iPtr.get() << std::endl;
  std::cout << iPtr.get()->_age << std::endl;
  std::cout << iPtr.get()->_name << std::endl;
}

int main(int argc, char const *argv[])
{
  std::cout << "A program to demonstrate unique_ptr\n";

  // initialization
  std::unique_ptr<Person> person1 (new Person("Ashok", 61)); // explicit creation c++11
  std::unique_ptr<Person> person2 = std::make_unique<Person>("Sam", 42); // C++14 onwards

  // doesn't work as copy/assignment are deleted functions
  // unique_ptr<Person> person22 = person2;
  // unique_ptr<Person> person23(person2);
  foo(person2);


  // get
  print("1. person2.get() ", person2.get());

  // move
  std::unique_ptr<Person> person24(std::move(person2));
  print("2. person2.get() ", person2.get());
  print("person24.get() ", person24.get());


  // reset
  person2.reset();
  print("person2.get() ", person2.get());

  // release
  std::unique_ptr<Person> person5 = std::make_unique<Person>("Suman", 55);
  person5.release();
  print("person5.get() ", person5.get());

  // issues
  Person* pPerson = new Person("Akash", 15);
  std::unique_ptr<Person> person3(pPerson);
  print("person3.get() ", person3.get());
  std::unique_ptr<Person> person4(pPerson);
  print("person4.get() ", person4.get());

  Person* personWho = nullptr;
  {
    std::unique_ptr<Person> person6 = std::make_unique<Person>("Manas", 45);
    personWho = person6.get();
    std::cout << personWho << std::endl;
  }
  std::cout << personWho << std::endl;
  print("personWho->_name : ", personWho->_name);
  print("personWho->_age : " , personWho->_age); 
  
  return 0;
}

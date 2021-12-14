#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <chrono>

struct Person
{
  Person(std::string name, int age) : _name(name), _age(age) {}
  ~Person() {}
  int _age;
  std::string _name;
};

#define SIZE 10000000

void Performance_new()
{
  auto start = std::chrono::system_clock::now();
  for (size_t i = 0; i < SIZE; i++)
  {
    Person *p = new Person("John", 55);
    delete p;
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "new         : " << dur.count() << " s\n";
}

void Performance_unique()
{
  auto start = std::chrono::system_clock::now();
  for (size_t i = 0; i < SIZE; i++)
  {
    std::unique_ptr<Person> p(new Person("John", 55));
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "unique_ptr  : " << dur.count() << " s\n";
}

void Performance_make_unique()
{
  auto start = std::chrono::system_clock::now();
  for (size_t i = 0; i < SIZE; i++)
  {
    std::unique_ptr<Person> p = std::make_unique<Person>("John", 55);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "make_unique : " << dur.count() << " s\n";
}

void Performance_shared()
{
  auto start = std::chrono::system_clock::now();
  for (size_t i = 0; i < SIZE; i++)
  {
    std::shared_ptr<Person> p(new Person("John", 55));
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "shared_ptr  : " << dur.count() << " s\n";
}

void Performance_make_shared()
{
  auto start = std::chrono::system_clock::now();
  for (size_t i = 0; i < SIZE; i++)
  {
    std::shared_ptr<Person> p = std::make_shared<Person>("John", 55);
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "make_shared : " << dur.count() << " s\n";
}

int main(int argc, char const *argv[])
{
  Performance_new();
  Performance_unique();
  Performance_make_unique();
  Performance_shared();
  Performance_make_shared();

  return 0;
}

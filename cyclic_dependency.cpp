#include <iostream>
#include <memory>

class B;

class A
{
  B* _pB;
  std::shared_ptr<B> _shB;
  // std::weak_ptr<B> _shB;

public:
  A(){std::cout << "A()" << std::endl; _pB = nullptr;}
  ~A(){std::cout << "~A()" << std::endl; /* if (_pB) {delete _pB;} */}
  
  void setB(B*& ipB) {_pB = ipB;}
  void setShB(std::shared_ptr<B>& ipB) {_shB = ipB;}
};

class B
{
  A* _pA;
  std::shared_ptr<A> _shA;
  // std::weak_ptr<A> _shA;

public:
  B(){std::cout << "B()" << std::endl; _pA = nullptr;}
  ~B(){std::cout << "~B()" << std::endl; /* if (_pA) {delete _pA;} */}

  void setA(A*& ipA) {_pA = ipA;}
  void setShA(std::shared_ptr<A>& ipA) {_shA = ipA;}
};

int main(int argc, char const *argv[])
{
  // A* pA = new A();
  // B* pB = new B();

  // pA->setB(pB);
  // pB->setA(pA);

  // delete pA;
  // delete pB;

  std::shared_ptr<A> spA(new A());
  std::shared_ptr<B> spB(new B());

  spA->setShB(spB);
  spB->setShA(spA);

  return 0;
}

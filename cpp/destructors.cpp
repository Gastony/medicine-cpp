#include <iostream>
using namespace std;

#include <new>

//destructors always called last to first

class A
{
public:
    ~A() { cout << "A destructor called\n" ; }
protected:
    void x();
};

class B: public A
{
public:
    ~B() { cout << "B destructor called\n" ; }
protected:
    void x();
};

int main()
{
    char memory[sizeof(A)];
    void * place = memory;

    std::cout << "size of A = " << sizeof(A) << std::endl;
    std::cout << "size of B = " << sizeof(B) << std::endl;
    
    A * f = new(place) A();

    f->~A(); //only case where a destructor is called explicitly

    B b;
    B * c = &b;
    c->~B();
    //c->~A(); compile error obviously
    
    //~B();
    
    return 0;
}

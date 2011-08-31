#include <iostream>

class B
{
public:
    int x;
    B() {};
    ~B() {};
};

class A
{
public:
    A(int x) { b.x = x; }
    ~A() {};
    const B & getB() const { return b; } 
private:
    B b;
};

int main()
{
    A a(2);

    std::cout << "non const ax =" << a.getB().x << std::endl;

    const A & ca = a;
    std::cout << "const ax =" << ca.getB().x << std::endl;

    const B & cb = ca.getB();
    std::cout << "const bx =" << cb.x << std::endl;

    return 0;
}

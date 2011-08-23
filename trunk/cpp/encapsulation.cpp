#include <iostream>

class Base
{
public:
    Base(int x) : x(x) {}
protected:
    int x;
};

class D2 : public Base
{
public:
    D2(int x) : Base(x) {}
    void printX() { std::cout << "x=" << x << std::endl; }
    int getX() const { return x; } 
};

class D1 : public Base
{
public:
    D1(int x) : Base(x) {}
    void printX() { std::cout << "x=" << x << std::endl; }
    void operator=(const D2 & d2);
};

void D1::operator=(const D2 & d2)
{
    const Base & b = d2;
    //std::cout << "x from Base is " << b.x << std::endl;
    // above line cannot access x directly from Base
    //but in below line we can access x using Derived pointer D1
    //directly
    
    this->x = d2.getX(); // can access x from Base but not from B2 directly
}


void printX(Base & b)
{
    //std::cout << "x=" << b.x << std::endl;
}

int main()
{
    Base b(2);
    //printX(b);

    D1 d1(3);
    d1.printX();

    D2 d2(4);
    d2.printX();

    d1 = d2;
    d1.printX();
    
    return 0;
}

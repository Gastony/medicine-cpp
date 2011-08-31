#include <iostream>
using namespace std;

class C
{
public:
    void printC() { cout << "print C\n"; }
};

class B
{
public:
    static C c;
};

class A
{
public:
    A(int y)  { B::c.printC();}
    ~A() {}
private:
    //static const int s = 2; //only works for CONST ints and enums, has to evaluate
                      //at compile time
    //static const B b = B(); // doesn't work non integral type
};

//int A::s = 2;

int main()
{
    A a(2);
    
    return 0;
}

C B::c;

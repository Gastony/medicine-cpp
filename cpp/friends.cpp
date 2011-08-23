#include <iostream>
using namespace std;

//friendship cannot be inherited, not transitive and not reciprocal

// member functions dont allow promotion of left hand argument

class A
{
public:
    /*A& operator+ (int b)
        {
            x += b;
            return *this;
            }*/

    A(int x) : x(x) {}
    int get() const { return x; }

    friend A operator+(int b, const A & a);
    
    friend A operator+(const A & a, int b);
private:
    int x;
};

A operator+(int b, const A & a)
{
    return A(b+a.get());
}
    
A operator+(const A & a, int b)
{
    return A(b+a.get());
}

int main()
{
    A a(2);
    cout << "x=" << a.get() << "\n";

    A b = a + 3;
    cout << "x=" << a.get() << "\n";
    cout << "x=" << b.get() << "\n";

    b = 2 + a; // not possible without friend function
    cout << "x=" << a.get() << "\n";
    cout << "x=" << b.get() << "\n";

    return 0;
}

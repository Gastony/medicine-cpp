#include <iostream>
using namespace std;

class A
{
public:
    A(int x) : z(x) {}

    A & operator= (const A & a)
        {
            if (this == &a)
            {
                cout << "refs equal nothing to do\n";
            }
            else
            {
                this->z = a.z;
            }

            return *this;
       }

    int z;
};

// for assignment operators - if we define one in derived class, we
// need to call the base class assignment operator in the derived clas
// implementation of assignment operator
//the compiler wont call automatically like in case of ctors and dtors

int main()
{
    A a(2);
    a = a;

    cout << "z=" << a.z << "\n";
    
    A b(3);
    a = b;
    cout << "z=" << a.z << "\n";
    
    return 0;
}

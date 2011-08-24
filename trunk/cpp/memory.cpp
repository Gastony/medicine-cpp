#include <iostream>

//new operator never returns NULL like malloc
//new calls constructor, returns right type and is over-ridable

//safe to call delete on NULL pointer
// delete calls destructor on the object and then releases memory

class X
{
public:
    void suicide () { delete this; }
    ~X() { std::cout << "destructor called\n"; }
};

int main()
{
    X x;
    x.suicide();

    X y;
    if (true) { return 0; }
    
    return 0;
}

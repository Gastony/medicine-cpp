//C++ cannot distinguish between pointer to an object and pointer to
//an array of objects

#include <iostream>

class X
{
public:
    virtual void f() = 0;
};
    
int main()
{
    //X x;
    return 0;
}

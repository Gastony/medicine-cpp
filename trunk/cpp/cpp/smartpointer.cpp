#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class X
{
};

void foo(std::vector<std::auto_ptr<X> > & v)
{
}

int main()
{
    std::auto_ptr<X> xptr;

    std::vector<std::auto_ptr<X> > v;

    //std::vector<std::tr1::shared_ptr<X> > s;
    
    foo(v);
    
    return 0;
}

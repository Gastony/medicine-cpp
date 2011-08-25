#include <iostream>
using namespace std;

class Base
{
public:
    int data;
};

class Der1: public virtual Base
{
};

class Der2: public virtual Base
{
};

class Grand: public Der1, public Der2 //cannot keep virtual here
{
};

int main()
{
    Grand g;
    g.data = 2;
    return 0;
}

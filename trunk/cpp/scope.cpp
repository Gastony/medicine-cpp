#include <iostream>

class A
{
public:
    A(int x) { this->x = x; std::cout << "C called x=" << x << std::endl;}
    ~A() { std::cout << "D called x=" << x << std::endl; }
    int x;
};
    
int main()
{

    int counter = 3;
    while (counter --)
    {
        A a(2);
        //int y = 3;
        if (counter) continue;
        a.x=4;
        std::cout << "a=" << a.x << std::endl;
    }
    return 0;
}

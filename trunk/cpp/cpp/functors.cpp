#include <iostream>
using namespace std;

class Functor
{
public:
    int f() {return 1;}
    int operator() () { cout << "functor\n"; return f(); }
};
int main()
{
    Functor f;
    f();
    return 0;
}

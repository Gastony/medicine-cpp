#include <iostream>
using namespace std;


template<class T>
void add_part(T a, T b)
{
}

template<>
void add_part<int>(int a, int b)
{
    cout << a+b+2 << "\n";
}

template <class T>
void add(T a, T b)
{
    cout << a+b << "\n";

    add_part(a, b);
}

template<> //template specialization
void add<const char*>(const char* a, const char* b)
{
    cout << "hello prasad\n";
}

// for template functions to participate in operator overloading,
// parameter types should match exactly..no conversions

int main()
{
    add(1,2);

    add(string("hello"), string(" prasad"));

    add("hello", " prasad");
    
    return 0;
}

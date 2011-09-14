#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
unsigned int reverseBits(unsigned int x)
{
    unsigned int r = x;
    int s = sizeof(x) * CHAR_BIT -1;
 
    for (x >>= 1; x; x >>= 1)
    {
        r <<= 1;
        r |= x & 1;
        s--;
    }
 
    r <<= s;
 
    return r;
}
 
std::string reverse(std::string str)
{
    int size = str.size();
    for (int i = 0; i < size/2; ++i)
    {
        char c = str[i];
        str[i] = str[size-i-1];
        str[size-i-1]=c;
    }
     
    return str;
}
 
std::ostream & binary(unsigned int x, std::ostream & os)
{
    os << x << "|";
    std::stringstream ss;
    while (x)
    {
        int k = x % 2;
        ss << k;
        x  = x / 2;
    }
    os << reverse(ss.str());
    os << endl;
 
    return os;
}
 
int main()
{
    unsigned int x = 123;
    unsigned int y = reverseBits(x);
    binary(x, cout);
    binary(y, cout);
    return 0;
}


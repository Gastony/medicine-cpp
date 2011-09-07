#include <iostream>
using namespace std;

//1/x+1/y=1/n!
int Solutions(int n)
{
  int nfact = fact(n);
}

int main()
{
  int n = 0;
  std::cin >> n;

  std::cout << ( Solutions(n) % 1000007 ) << endl;
 
  return 0;
}

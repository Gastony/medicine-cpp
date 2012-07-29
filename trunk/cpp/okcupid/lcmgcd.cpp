#include <iostream>
using namespace std;

int lcm(int a, int b)
{
	int lcm = (a > b) ?  a : b;
	int inc = lcm;
	
	while ((lcm % a != 0) || (lcm % b != 0))
	{
		lcm += inc;
	}
	
	return lcm;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	
	return (a > b) ? gcd(a-b, b) : gcd(a, b-a);
}

int main()
{
	int a = 6, b = 4;
	
	cout << "lcm = " << lcm(a,b) << "\n";
	
	cout << "gcd = " << gcd(a,b) << "\n";
	
	return 0;
}
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

bool is_prime(int n)
{
	if (n < 2)
	{
		return false;
	}
	
	if ( 2 == n)
	{
		return true;
	}
	
	if (0 == n%2)
	{
		return false;
	}
	
	int m = sqrt(n);
	for (int j = 3; j <= m; j+=2)
	{
		if (0 == n%j)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	int n = 1000;
	int temp = n;
	
	int m = sqrt(n);
	std::cout << "sqrt of " << n << " is " << m << std::endl;
	
	std::vector<int> result;
	for (int i = 2; i <= m && temp > 1; ++i)
	{
		if (is_prime(i))
		{
			while(0 == temp % i)
			{
				result.push_back(i);
				temp = temp / i;
			}
		}
	}
	
	if (n < 2)
	{
		std::cout << n << " has no prime factors" << std::endl;
		return 0;
	}
	
	std::vector<int>::const_iterator it;
	std::stringstream ss;
	ss << n << " = ";
	for (it = result.begin(); it != result.end(); ++it)
	{
		ss << *it << " * ";
	}
	
	std::string out = ss.str();
	out.erase(out.end()-3, out.end()-1);
	
	std::cout << out << std::endl;
	
	return 0;
}
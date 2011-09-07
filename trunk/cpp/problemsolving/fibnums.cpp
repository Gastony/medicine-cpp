#include <iostream>
#include <vector>

void generate_n_fibs(std::vector<int>& fibs, int n)
{
	if (n < 1)
	{
		return;
	}
	
	if (1 == n)
	{	
		generate_n_fibs(fibs, n-1);
		fibs.push_back(0);
	}
	else if (2 == n)
	{
		generate_n_fibs(fibs, n-1);
		fibs.push_back(1);
	}
	else
	{
		generate_n_fibs(fibs, n-1);
		fibs.push_back(fibs.at(fibs.size()-1) + fibs.at(fibs.size()-2));
		
	}
}

int main()
{
	std::vector<int> fibs;
	generate_n_fibs(fibs, 10);
	
	std::vector<int>::const_iterator it;
	for (it = fibs.begin(); it != fibs.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}
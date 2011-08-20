#include <vector>
#include <iostream>

bool binary_search(const std::vector<int> & array, const int target)
{
	int lo = 0;
	int hi = array.size() - 1;
	
	while (lo <= hi)
	{
		int mid = lo + (hi-lo)/2;
		
		int curr = array.at(mid);
		std::cout << "mid= " << mid << " curr= " << curr << std::endl;
		if (target == curr)
		{
			return true;
		}
		else if (target > curr)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	
	return false;
}

int main()
{
	int data[] = {1, 3, 7, 11, 12};
	std::vector<int> test(data, data+sizeof(data)/sizeof(data[0]));
	
	if (binary_search(test, 3))
	{
		std::cout << "element found" << std::endl;
	}
	else
	{
		std::cout << "element not found" << std::endl;
	}
	
	if (binary_search(test, 10))
	{
		std::cout << "element found" << std::endl;
	}
	else
	{
		std::cout << "element not found" << std::endl;
	}
	
	return 0;
}
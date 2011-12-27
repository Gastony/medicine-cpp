#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: ./a.out <filename>\n";
	}
	
	std::vector<float> nums;
	string input;
	while (getline(cin, input))
	{
		nums.push_back(atof(input.c_str()));
	}
	
	sort(nums.begin(), nums.end());
	
	std::ofstream f(argv[1], std::ios::out);
	int len = nums.size();
	if (len % 2 == 0)
	{
		f << (nums[len/2] + nums[len/2-1])/2 << "\n";
	}
	else
	{
		f << nums[len/2] << "\n";		
	}
	f.close();
	
	return 0;
}
#include <iostream>
#include <sstream>
using namespace std;

void print(const char * input)
{
	const char * curr = input;
	if (!curr || *curr == '\0') return;
	
	const char * next = curr + 1;
	if (!(*next))
	{
		cout << *curr << "\n";
		return;
	}
	
	int counter = 1;
	stringstream ss;
	char prev = '\0';
	while (*next)
	{
		if (*curr != *next)
		{
			if (counter == 1)
			{
				ss << *curr;
			}
			counter = 0;
		}
		
		++next;
		prev = *curr;
		++curr;
		++counter;
	}
	
	if (counter == 1 && *curr != prev)
	{
		ss << *curr;
	}
	
	cout << ss.str() << "\n";
}

int main()
{
	print("xxyyyxyzx");
	print("xxyx");
	print("xyzx");
	print("x");
	print("xx");
	print("xy");
	
	return 0;	
}
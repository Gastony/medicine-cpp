#include <iostream>
using namespace std;

void fizzbuzz()
{
  bool not3not5 = true;
  for (int i = 1; i <= 100; ++i)
    {
      if (i % 3 == 0)
	{
	  cout << "Fizz";
	  not3not5 = false;
	}
      if (i % 5 == 0)
	{
	  cout << "Buzz";
	  not3not5 = false;
	}

      if (not3not5)
	{
	  cout << i;
	}
      else
	{
	  not3not5 = true;
	}
      cout << endl;
    }
}

int main()
{
  fizzbuzz();
  return 0;
}

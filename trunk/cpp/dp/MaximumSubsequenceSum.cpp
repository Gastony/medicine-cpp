#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MaximumSubsequenceSum(int test[], int length)
{
  std::vector<int> sums; sums.resize(length);

  if (length < 1) return;

  int curr_sum = test[0];
  sums[0] = curr_sum;
  for (int i = 1; i < length; ++i)
    {
      if (test[i] < 0)
	{
	  curr_sum = 0;
	  sums[i] = (test[i] > sums[i-1]) ? test[i] : sums[i-1];
	}
      else
	{
	  curr_sum += test[i];
	  sums[i] = (curr_sum > sums[i-1]) ? curr_sum : sums[i-1];
	}
    }

  for (int i = 0; i < length; ++i)
    {
      cout << i << "|" << sums[i] << endl;
    }
}

int main()
{
  //int test[] = {1, 2, 3, 6, 8, 5, 4, 2, -1, 78, -45, -2, 18};
  int test[] = {-12, -2, -3, -6, -8, -5, -4, 2, -1, -23, -45, -2, -78, 0, -1};
  MaximumSubsequenceSum(test, 14);

  return 0;
}

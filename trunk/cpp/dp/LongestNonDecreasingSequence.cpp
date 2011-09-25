#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void LongestNonDecreasingSequence(int a[], int length)
{
  std::vector<int> veci;
  std::vector<int> vecj;
  std::vector<int> veclong;
  veci.resize(length); vecj.resize(length); veclong.resize(length);

  fill(veci.begin(), veci.end(), 0);
  fill(vecj.begin(), vecj.end(), 0);
  fill(veclong.begin(), veclong.end(), 0);

  if (length < 1) return;

  veclong[0] = 1;
  int curr_i = 0;
  int curr_j = 0;
  int curr_len = 1;
  for (int i = 1; i < length; ++i)
    {
      if (a[i] >= a[i-1])
	{ 
	  ++curr_len; 
	}
      else
	{
	  curr_len = 1;
	  curr_i = i;
	}
      curr_j = i;

      if (curr_len > veclong[i-1])
	{
	  veclong[i] = curr_len;
	  vecj[i] = curr_j;
	  veci[i] = curr_i;
	}
      else
	{
	  veclong[i] = veclong[i-1];
	  veci[i] = veci[i-1];
	  vecj[i] = vecj[i-1];
	}
    }

  for (int i = 0; i < length; ++i)
    {
      cout << veci[i] << "|" << vecj[i] << "|" << veclong[i] << endl;
    }
}

int main()
{
  int test[] = {1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3};
  LongestNonDecreasingSequence(test, 26);
  return 0;
}

#include <iostream>
using namespace std;

#include <map>

int Solutions(std::map<int, int> & data, int k)
{
  std::map<int, int>::const_iterator iter = data.begin();
  int count = 0;
  int tmp = 0;
  for (; iter != data.end(); ++iter)
    {
      tmp = iter->first - k;
      if (data.find(tmp) != data.end()) ++count;
    }
  return count;
}

int main()
{
  int n = 0;
  std::cin >> n;

  int k  = 0;
  std::cin >> k;

  //cout << "input: n = " << n << endl;
  //cout << "input: k = " << k << endl;

  int tmp = n;
  std::map<int, int> data;
  int i = 0;
  while (tmp--)
    {
      std::cin >> i;
      data[i] = 1;
    }

  cout << Solutions(data, k) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<std::string> getPermutations(const std::string & s)
{
  std::vector<std::string> perms;
  if (s.size() == 1)
    {
      perms.push_back(s);
      return perms;
    }

  std::string first = s.substr(0, 1);
  std::string sub = s.substr(1);

  //cout << first << "|" << sub << endl;
  perms = getPermutations(sub);

  std::vector<std::string>::iterator iter = perms.begin();
  std::vector<std::string> new_perms;
  for (; iter != perms.end(); ++iter)
    {
      std::string curr = *iter;
      int length = curr.size();
      for (int i = 0; i <= length; ++i)
	{
	  new_perms.push_back(curr.substr(0,i) + first + curr.substr(i));
	}
      //cout << *iter << "|" << first << endl;
    }
  return new_perms;
}

int main()
{
  std::string s("her");
  std::vector<std::string> perms = getPermutations(s);
  std::vector<std::string>::iterator iter = perms.begin();
  for (; iter != perms.end(); ++iter)
    {
      cout << *iter << "\n";
    }

  return 0;
}

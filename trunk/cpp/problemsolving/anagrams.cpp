#include <iostream>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>

void printAnagrams(const std::vector<std::string> & v)
{
  std::tr1::unordered_map<std::string, std::vector<std::string> > anagramsMap;

  std::vector<std::string>::const_iterator iter = v.begin();
  std::tr1::unordered_map<std::string, std::vector<std::string> >::iterator aIter;
  for (; iter != v.end(); ++iter)
    {
      std::string sorted(*iter);
      sort(sorted.begin(), sorted.end());
      aIter = anagramsMap.find(sorted);
      if (aIter == anagramsMap.end())
	{
	  std::vector<std::string> l;
	  l.push_back(*iter);
	  anagramsMap[sorted] = l;
	}
      else
	{
	  aIter->second.push_back(*iter);
	} 
    }

  aIter = anagramsMap.begin();
  for (; aIter != anagramsMap.end(); ++aIter)
    {
      std::cout << aIter->first << ":";
      std::vector<std::string>::const_iterator iter = aIter->second.begin();
      for (; iter != aIter->second.end(); ++iter)
	{
	  std::cout << " " << *iter; 
	}
      std::cout << std::endl;
      }
}

int main()
{
  std::vector<std::string> l;
  l.push_back("hello");
  l.push_back("ehllo");
  l.push_back("rama");
  l.push_back("mara");

  printAnagrams(l);

  return 0;
}

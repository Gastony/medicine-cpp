#include <iostream>

using namespace std;

void reverse(char * str, int start, int end)
{
  if (str == NULL) return;
 
 while (start < end)
    {
      char tmp = str[start];
      str[start] = str[end];
      str[end] = tmp;
      ++start; --end;
    }
}

void reverse_words(char * str)
{
  if (str == NULL) return;
  
  reverse(str);
  int len = std::strlen(str);
  int start = 0; int end = 0;

  while (end < len)
    {
      while (end < len && str[end] == ' ') end++;
      if (end >= len) return;
      start = end;
      while (end < len && str[end] != ' ') ++end;
      if (end < len)
	{
	  reverse(str, start, end-1);
	}
    }
}

int main()
{
  char * sen = "hello how are you";
  reverse_words(sen);
  std::cout << sen << "\n";

  return 0;
}

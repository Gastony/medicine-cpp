#include <iostream>
using namespace std;

int find_first_char_pat_in_src(char * src, char * pat, int i, int src_len);

int substring_match(char * src, char * pat)
{
  if (src == NULL || pat == NULL) return -1;

  int src_len = strlen(src);
  int pat_len = strlen(pat);

  for (int i = 0; i < src_len; ++i)
    {
      i = find_first_char_pat_in_src(src, pat, i, src_len);
      if (i == -1 || (src_len - i < pat_len) ) return -1;
      
      int  j = 0;
      for (int k = i; k < src_len && j < pat_len; ++k, ++j)
	{
	  if (src[k] == pat[j]) continue;
	  else break;
	}
      if (j == pat_len) return i;
    }

      return -1;
}

  int find_first_char_pat_in_src(char * src, char * pat, int i, int src_len)
  {
    for (int k = i; k < src_len; ++k)
      {
	if (src[k] == pat[0]) return k;
	else continue;
      }
    return -1;
  }

int main()
{
  int i = substring_match("hello", "hellox");
  std::cout << "i=" << i << std::endl;
  return 0;
}

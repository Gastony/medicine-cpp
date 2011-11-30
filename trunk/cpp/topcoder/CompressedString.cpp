/* Top coder problem
http://community.topcoder.com/stat?c=problem_statement&pm=7321
Problem Statement
    	
Uncompress the given string s in the following manner: Find a section that matches the pattern "k(q)" (quotes for clarity only), where k is a single digit, the two parentheses are a matching set, and q is zero or more characters. Replace the entire section with k consecutive occurrences of q. Repeat this process until there are no more such patterns. Return the length of the uncompressed string.

 
Definition
    	
Class:	CompressedString
Method:	getLength
Parameters:	String
Returns:	int
Method signature:	int getLength(String s)
(be sure your method is public)
    
 
Constraints
-	s will contain between 0 and 50 characters, inclusive.
-	s will contain only digits ('0'-'9') and parentheses ('(',')').
-	The parentheses in s will be properly matched.
-	Each opening parenthesis ('(') in s will be preceded by a digit ('0'-'9').
-	The return value will be less than or equal to 2147483647.
*/

#include <iostream>
#include <string>
#include <stack>

class CompressedString
{
public:
  int getLength(const std::string & s)
  {
    int length = s.size();
    if (length < 4)
      {
	return length; //need atleast 4 chars for k(q)
      }
    
    std::stack<char> stk;
    int i = 0;
    int counter = 0;
    while (i < length)
      {
	if (s[i] != ')')
	  {
	    stk.push(s[i]); 
	  }
	else
	  {
	    int substrLength = 0;
	    while (!stk.empty())
	      {
		char x = stk.top();
		stk.pop();
		if (x == '(')
		  {
		    break;
		  }
		++substrLength;
	      }
	    char multiplier = stk.top(); stk.pop();
	    counter = (multiplier - '0') * (counter + substrLength);
	  }
	++i;
      }
    
    while (!stk.empty())
      {
	++counter; stk.pop();
      }
   
    return counter;
  }
};

void Test(const std::string & test)
{
  CompressedString cs;
  std::cout << "Input: " << test << std::endl;
  std::cout << "Output: " << cs.getLength(test) << std::endl;
}

int main()
{
  std::string test("123");
  Test(test);

  test = "10342(76)";
  Test(test);

  test = "10342(76)8";
  Test(test);

  test = "33(562(71(9)))";
  Test(test);

  test = "22(22(22(22)22)22)22";
  Test(test);

  test = "0(0)";
  Test(test);

  test = "1(1(1(1(1(1(1(0(1234567890))))))))";
  Test(test);

  test = "1()66(5)";
  Test(test);

  test = "1(2)";
  Test(test);

  return 0;
}

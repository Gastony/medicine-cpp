/* Top Coder problem
   http://community.topcoder.com/stat?c=problem_statement&pm=7591

   Problem Statement
    	You are a developer for a financial computer system. Users of
    	the system often operate with  large numbers, so it's
    	important that numbers be  formatted in an easy-to-read
    	manner.  You are given a String number containing the internal
    	representation of a non-negative number. This number will
    	contain only  digits, along with an optional decimal separator
    	represented by a comma (','). Format the number as follows:

1. If the number contains a decimal separator, replace the decimal separator with a period ('.').

2. Divide the integer part of the number into groups of three
   consecutive  digits, from right to left. Depending on the number of
   digits,  the left-most group might only contain 1 or 2
   digits. Insert a  single space (' ') between each pair of
   consecutive  groups. (The integer part of the number is the part of
   the  number to the left of the decimal separator if one exists, or
   the  entire number if there is no decimal separator.)

For example, "1234567,890" would be formatted as "1 234 567.890" and
"1024" would be  formatted as "1 024". If insignificant leading or
trailing  zeroes exist in the number, they must be preserved. For
example,  "00003,1234000" would be formatted "00 003.1234000". Return
the formatted version of the given number.
 
Definition
    	
Class:	NumberFormatter
Method:	format
Parameters:	String
Returns:	String
Method signature:	String format(String number)
(be sure your method is public)
    
 
Constraints
-	number will contain between 1 and 50 characters, inclusive.
-	Each character in number will be either a digit ('0'-'9') or a comma (',').
-	number will contain at most one comma (',').
-	Comma (',') will not be the first or the last character of number.
*/

#include <string>
#include <iostream>
#include <sstream>

class NumberFormatter
{
public:
  std::string format(const std::string & number)
	{		
    	std::stringstream ss;
    
    	size_t pos = number.find(',');
	
    	int integerLength = (pos == std::string::npos) ? number.size() : pos;
	
    	int numGroups = integerLength / 3;
    	int firstGroupLength = integerLength % 3;

        if (0 != firstGroupLength)
        {
            ss << number.substr(0, firstGroupLength);
            if (numGroups != 0)
            {
                ss << " ";
            }
        }

        int iter = firstGroupLength;
        while (numGroups--)
        {
            ss << number.substr(iter, 3);
            if (0 != numGroups)
            {
        	    ss << " ";
            }
            iter += 3;
        }
        
        if (integerLength != number.size())
        {
            ss << "." << number.substr(pos + 1);
        }
        
        return ss.str();
    }
};

int main()
{
  NumberFormatter nf;
    std::string input("1234567,890");
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << nf.format(input) << "\n";

    input = "1024";
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << nf.format(input) << "\n";

    input = "1,024";
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << nf.format(input) << "\n";

    input = "00003,1234000";
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << nf.format(input) << "\n";

    input = "12345678912345678912345,0987654321";
    std::cout << "Input: " << input << "\n";
    std::cout << "Output: " << nf.format(input) << std::endl;

    return 0;
}

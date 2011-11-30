/*
  Top Coder Problem
  http://community.topcoder.com/stat?c=problem_statement&pm=11219
  Problem Statement
  Fox Ciel likes sequences. One day, she invented a new type of
  sequence and
  named it the fox sequence. A sequence seq containing N elements is
  called a fox sequence if and only if there exist four integers a, b,
  c and d
  such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

  seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a
  positive common
  difference. An arithmetic progression is a sequence where the
  difference between
  successive elements is equal. The difference between successive
  elements is called the
  common difference. Note that 0 is neither positive nor negative.
  seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with
  a negative
  common difference.
    seq[b], seq[b+1], ... , seq[c] are all equal.
    seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression
  with a positive
  common difference.
  seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression
  with a
  negative common difference.
  You are given a sequence seq. Return "YES" if it is a fox sequence,
  or "NO"
  if it is not (all quotes for clarity).
 
Definition
    	
Class:	FoxSequence
Method:	isValid
Parameters:	int[]
Returns:	String
Method signature:	String isValid(int[] seq)
(be sure your method is public)
    
 
Constraints
-	seq will contain between 1 and 50 elements, inclusive.
-	Each element of seq will be between 1 and 2,000, inclusive.
*/

#include <vector>
#include <string>
#include <iostream>
#include <cassert>
    
class FoxSequence
{
public:
  std::string isValid(const std::vector<int> & seq)
        {
            int length = seq.size();
            // need atleast 5 elements to satisfy 0 < a < b <= c < d < N-1
            if (length < 5)
            {
                return std::string("NO");
            }

            int a = 0, b  = 0, c = 0, d = 0, e = 0;
            // case: seq[0], seq[1], ... , seq[a] forms an arithmetic
            // progression with a positive common difference. 
            int i = 0;
            a = checkSequence(seq, i, 1);
            if (a == -1 || (a == length-1) || (length - a < 4))
            {
                return std::string("NO");
            }
            
            //case: seq[a], seq[a+1], ... , seq[b] forms an arithmetic
            //progression with a negative common difference.
            b = checkSequence(seq, a, -1);
            if (b == -1 || (b == length-1) || (length - b < 3))
            {
                return std::string("NO");
            }
            
            //case: seq[b], seq[b+1], ... , seq[c] are all equal.
            c = checkSequence(seq, b, 0);
            if ((c == length-1) || (length - c < 3))
            {
                return std::string("NO");
            }

            //case: seq[c], seq[c+1], ... , seq[d] forms an arithmetic
            //progression with a positive common difference.
            d = checkSequence(seq, c, 1);

            if (d == -1 || (d == length-1) || (length - d < 2))
            {
                return std::string("NO");
            }
            
            //case: seq[d], seq[d+1], ... , seq[N-1] forms an
            //arithmetic progression with a negative common
            //difference.
            e = checkSequence(seq, d, -1);

            if (e != length-1)
            {
                return std::string("NO");
            }

            //std::cout << a << "|" << b << "|" << c << "|" << d << "|"
            //        << e << "\n";
            
            return std::string("YES");
        }
private:
  int checkSequence(
        const std::vector<int> & seq,
        int startIndex,
        int equalityType)
        {
            int diff = seq[startIndex+1] - seq[startIndex];

            if ((equalityType == 1 && diff <= 0) ||
                (equalityType == -1 && diff >= 0))
            {
                return -1;
            }

            if (equalityType == 0 && diff != 0)
            {
                return startIndex;
            }
            
            ++startIndex;

            int length = seq.size();
            while ((startIndex < length-1) && ((seq[startIndex+1] - seq[startIndex]) == diff))
            {
                ++startIndex;
            }

            return startIndex;
        }
};

int main()
{
  FoxSequence fs;

    int test1[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1};
    std::vector<int> seq1(test1, test1 + sizeof(test1) / sizeof(int));
    std::cout << fs.isValid(seq1) << "\n";

    int test2[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4};
    std::vector<int> seq2(test2, test2 + sizeof(test2) / sizeof(int));
    std::cout << fs.isValid(seq2) << "\n";

    int test3[] = {3,6,9,1,9,5,1};
    std::vector<int> seq3(test3, test3 + sizeof(test3) / sizeof(int));
    std::cout << fs.isValid(seq3) << "\n";

    int test4[] = {1,2,3,2,1,2,3,2,1,2,3,2,1};
    std::vector<int> seq4(test4, test4 + sizeof(test4) / sizeof(int));
    std::cout << fs.isValid(seq4) << "\n";

    int test5[] = {1,3,4,3,1,1,1,1,3,4,3,1};
    std::vector<int> seq5(test5, test5 + sizeof(test5) / sizeof(int));
    std::cout << fs.isValid(seq5) << "\n";

    int test6[] = {6,1,6};
    std::vector<int> seq6(test6, test6 + sizeof(test6) / sizeof(int));
    std::cout << fs.isValid(seq6) << "\n";

    int test7[] = {1,2,1,2,1,2};
    std::vector<int> seq7(test7, test7 + sizeof(test7) / sizeof(int));
    std::cout << fs.isValid(seq7) << std::endl;
    
    return 0;
}


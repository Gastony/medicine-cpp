/* Top coder problem
   http://community.topcoder.com/stat?c=problem_statement&pm=11423

   Problem Statement
        

   You are given two Strings s and t. All characters of s and t are
   distinct.
   No character of s is present in t and no character of t is present in s.

   Let N be the length of s, and M be the length of t. Define a
   2-dimensional string array "table"
   as follows:

    table[i][0] = s[i-1] (1<=i<=N)
    table[0][j] = t[j-1] (1<=j<=M)
    table[i][j] = min(table[i-1][j], table[i][j-1]) +
    max(table[i-1][j], table[i][j-1])
    (1<=i<=N, 1<=j<=M)

    Note that min and max are defined by the lexicographical order of
    strings
    (see Notes for a more formal definition), and A+B means the concatenation of strings A and B.

    Your task is to find a substring of table[N][M]. Let L be the
    length of table[N][M].
    Return the substring of table[N][M] whose start position
    (0-indexed) is pos and
    length is min(50, L-pos).
 
Definition
        
Class:    STable
Method:    getString
Parameters:    String, String, long
Returns:    String
Method signature:    String getString(String s, String t, long pos)
(be sure your method is public)
    
 
Notes
-    A string X is defined as smaller than a string Y if and only if X
is a prefix of Y or X
has a smaller character than Y at the first position where they differ.
-    The order of characters is defined by their ASCII codes: '0'<...<'9'<'A'<...<'Z'<'a'<...<'z'.
 
Constraints
-    s and t will each contain between 1 and 30 characters, inclusive.
-    All characters of s and t will be distinct.
-    No character of s will be present in t.
-    No character of t will be present in s.
-    s and t will contain only letters ('A'-'Z', 'a'-'z') and digits ('0'-'9').
-    pos will be between 0 and L-1, inclusive, where L is the length of
table[N][M] as defined in the statement.
*/

#include <iostream>
#include <string>
#include <vector>

class STable
{
public:
    static std::string getString(
        const std::string & s,
        const std::string & t,
        const long pos)
        {
            std::vector<std::vector<std::string> > table;
            buildTable(table, s, t);
            printTable(table);
            
            return std::string("");
        }
private:
    static void buildTable(
        std::vector<std::vector<std::string> > & table,
        const std::string & s,
        const std::string & t)
        {
            int N = s.size();
            table.resize(N + 1);
            int M = t.size();
            for (int i = 0; i < N+1; ++i)
            {
                table[i].resize(M + 1);
            }

            table[0][0] = std::string(" ");

            for (int i = 1; i <= N; ++i)
            {
                table[i][0] = std::string(1, s[i-1]);
            }

            for (int j = 1; j <= M; ++j)
            {
                table[0][j] = std::string(1, s[j-1]);
            }

            for (int i = 1; i <= N; ++i)
            {
                for (int j = 1; j <= M; ++j)
                {
                    table[i][j] =
                    getMin(table[i-1][j], table[i][j-1]) + getMax(table[i-1][j], table[i][j-1]);
                }
            }
        }

    static void printTable(
        const std::vector<std::vector<std::string> > & table)
        {
            std::cout << "Table" << std::endl;
            int N = table.size();

            if (N == 0) return;

            int M = table[0].size();

            for (int i = 0; i < N+1; ++i)
            {
                std::cout << "|";
                for (int j = 0; j < M+1; ++j)
                {
                    std::cout << table[i][j] << "|";
                }
                std::cout << std::endl;
            }
        }

    static std::string getMin(const std::string & first, const std::string & second)
        {
            return (first < second) ? first : second;
        }

    static std::string getMax(const std::string & first, const std::string & second)
        {
            return (first > second) ? first : second;
        }
        
};

int main()
{
    std::string s("ad"), t("cb");
    std::cout << "Input: " << s << "|" << t << "|" << 0 << std::endl;
    std::cout << "Output: " << STable::getString(s, t, 0) << std::endl;
    
    return 0;
}

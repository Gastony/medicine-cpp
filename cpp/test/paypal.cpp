#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*int f (int num)
    {
            int out = 0;

            for (; num > 0; num /= 10) {
                    int d = num % 10;
                    out *= 10;
                    out += d;
            }

            return out;
    }

void g(int num, int & out)
{
	if (num > 0)
	{
		int d = num % 10;
		out *= 10;
		out += d;
		g(num/10, out);
	}
}*/

/*
The string "paypal is the faster, safer way to send money" is written in a 
clockwise spiral pattern inside a square starting from the upper left 
corner: 
(you may want to display this pattern in a fixed font for better legibility).

	P A Y P A L
	F E R W A I
	A M O N Y S
	S D Y E T T
	R N E S O H
	E T S A F E


Then read line after line:
	PAYPALFERWAIAMONYSSDYETTRNESOHETSAFE

Write the code that will take a string, calculate the minimum square that 
will contain it and return the converted string:
convert("paypalisthefastersaferwaytosendmoney") should return 
"paypalferwaiamonyssdyettrnesohetsafe"
*/
string convert(const string & s)
{
	int len = s.size();
	
	//base case
	if (len == 0) return string("");
	
	// minimum square calculation
	int i = 1;
	while (i*i < len) ++i;
	//cout << "i=" << i << endl;
	
	//matrix initialization
	vector<vector<char> > matrix;
	matrix.resize(i);
	for (int j = 0; j < i; ++j)
		matrix[j].resize(i);
	for (int j = 0; j < i; ++j)
		for (int k = 0; k < i; ++k)
			matrix[j][k] = ' ';
	
	//logic
	int r = 0, c = 0;
	bool right = true, down = false, left = false, up = false;	
	int curr_len = 0;
	int side = i - 1;
	while (curr_len < len)
	{
		if (right)
		{
			for (int j = 1; (j <= side) && ((curr_len+j) <= len); ++j)
			{
				matrix[r][c] = s[curr_len];
				//cout << curr_len << "|" << r << "|" << c << "|" << matrix[r][c] << "\n";
				++c;
				++curr_len;
			}
			
			right = false;
			down = true;
		}
		
		if (down)
		{
			for (int j = 1; (j <= side) && ((curr_len+j) <= len); ++j)
			{
				matrix[r][c] = s[curr_len];
				//cout << curr_len << "|" << r << "|" << c << "|" << matrix[r][c] << "\n";
				++r;
				++curr_len;
			}
			
			down = false;
			left = true;
		}
		
		if (left)
		{
			for (int j = 1; (j <= side) && ((curr_len+j) <= len); ++j)
			{
				matrix[r][c] = s[curr_len];
				//cout << curr_len << "|" << r << "|" << c << "|" << matrix[r][c] << "\n";
				--c;
				++curr_len;
			}
			
			left = false;
			up = true;
		}
		
		if (up)
		{
			for (int j = 1; (j <= side) && ((curr_len+j) <= len); ++j)
			{
				matrix[r][c] = s[curr_len];
				//cout << curr_len << "|" << r << "|" << c << "|" << matrix[r][c] << "\n";
				--r;
				++curr_len;
			}
			
			up = false;
			right = true;
			side = side - 2;
			++r; ++c;
		}
	}
	
	stringstream ss;
	
	for (int j = 0; j < i; ++j)
	{
		for (int k = 0; k < i; ++k)
		{
			ss << matrix[j][k];
		}
	}
			
	return ss.str();
}

int main()
{
	string s("paypalisthefastersaferwaytosendmoney");
	//string s("abcd");
	cout << "[" << convert(s) << "]" << endl;
	
/*cout << f(123) << "\n";
int i = 0;
g(310, i);
cout << i << "\n";*/

	return 0;
}
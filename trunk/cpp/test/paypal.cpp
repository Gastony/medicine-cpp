#include <iostream>
#include <string>
#include <vector>
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

string convert(const string & s)
{
	int len = s.size();
	if (len == 0) return string("");
	
	int i = 1;
	while (i*i < len) ++i;
	
	//matrix initialization
	vector<vector<char> > matrix;
	matrix.resize(i);
	for (int j = 0; j < i; ++j)
		matrix[j].resize(i);
	for (int j = 0; j < i; ++j)
		for (int k = 0; k < i; ++k)
			matrix[j][k] = ' ';
	
	//logic
	while (len )
}

int main()
{
	string s("paypalisthefastersaferwaytosendmoney");
	cout << convert(s) << endl;
/*cout << f(123) << "\n";
int i = 0;
g(310, i);
cout << i << "\n";*/

	return 0;
}
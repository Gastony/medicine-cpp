#include <iostream>
using namespace std;

/*ax+by=1
a and b are relatively prime
find integers x and y
*/

void gcdpair(int a, int b, int & x, int & y)
{
	if (a == 1)
	{
		x = 1; y = 0; return;
	}
	
	if (b == 1)
	{
		x = 0; y = 1; return;
	}
	
	if (a < b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	
	int old_r = a; int new_r = b;
	int old_x = 1; int new_x = 0;
	int old_y = 0; int new_y = 1;
	
	int q = a / b;
	int tmp_x = new_x; int tmp_y = new_y;
	
	new_x = old_x - q * new_x;
	old_x = tmp_x;
	
	new_y = old_y - q * new_y;
	old_y = tmp_y;
	
	int tmp_r = a * new_x + b * new_y;
	while (tmp_r != 1)
	{
		q = new_r / tmp_r;
		new_r = tmp_r;
		
		tmp_x = new_x;
		new_x = old_x - q * new_x;
		old_x = tmp_x;
		
		tmp_y = new_y;
		new_y = old_y - q * new_y;
		old_y = tmp_y;
		
		tmp_r = a * new_x + b * new_y;
	}
	
	x = new_x; y = new_y;
}

int main()
{
	int x = 0, y = 0; 
	gcdpair(25, 16, x, y);
	cout << x << "|" << y << endl;
	return 0;
}
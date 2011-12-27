#include <iostream>
using namespace std;

bool check_balance(string sql)
{
	int len = sql.size();
	bool insideLiteral = false;
	int counter = 0;
	for (int i = 0; i < len; ++i)
	{
		if (sql[i] == '\'')
		{
			if (!insideLiteral) insideLiteral = true;
			else insideLiteral = false;
		}
		
		if (insideLiteral) continue;
		
		if (sql[i] == '(') ++counter;
		if (sql[i] == ')') --counter;
	}
	
	if (counter == 0)
		return true;
	return false;
}

int main()
{
	cout << check_balance("SELECT (*)") << "\n";
	cout << check_balance("INSERT (") << "\n";
	cout << check_balance("SELECT * FROM b where a='F('") << "\n";
	
	return 0;
}
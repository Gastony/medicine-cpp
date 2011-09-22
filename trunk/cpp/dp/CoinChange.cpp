#include <iostream>
#include <vector>
using namespace std;

void PrintResult(const std::vector<int> & result)
{
    std::vector<int>::const_iterator iter = result.begin();
    cout << "solution size: " << result.size() << endl;
    cout << "Sum" << "|" << "MinCoins" << endl;
    int i = 0;
    for (; iter != result.end(); ++iter)
    {
        cout << i++ << "|" << *iter << endl;
    }
}

std::vector<int> FindMinimumCoins(int test[], int length, int sum,
                                  std::vector<int> & coins)
{
    std::vector<int> min;
    min.resize(sum+1);
    std::vector<int>::iterator iter = min.begin();
    for (; iter != min.end(); ++iter)
    {
        *iter = INT_MAX;
    }

    min[0] = 0;
    for (int i = 1; i <= sum; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            if (test[j] <= i && (1+min[i-test[j]] < min[i]))
            {
                min[i] = 1 + min[i-test[j]];
            }
        }
    }
    
    return min;
}

int main()
{
    int test[] = {25, 10, 4, 1};
    int sum = 41;

    std::vector<int> coins;
    std::vector<int> result = FindMinimumCoins(test, 4, sum, coins);
    PrintResult(result);
    PrintResult(coins);
    
    return 0;
}


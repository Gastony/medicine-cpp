#include <iostream>
#include <vector>
 
int findMaxSum(const std::vector<int> & v)
{
    int length = v.size();
    int maxSum = v[0];
    int sum = 0;
    for (int i = 1; i < length; ++i)
    {
        sum += v[i];
        if (maxSum < sum)
        {
            maxSum = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }
 
    return maxSum;
}
 
int main()
{
    int a[] = {-3,-4,-7, -2, -3, -1};
    std::vector<int> v(a, a + sizeof(a)/sizeof(int));
    int max = findMaxSum(v);
 
    std::cout << max << std::endl;
     
    return 0;
}


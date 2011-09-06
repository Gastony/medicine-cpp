#include <iostream>

int rand5()
{
    return rand() % (5-1+1) + 1;
}

int rand7()
{
    int x = 120;
    while (x > 119)
    {
        //uniform distribution is the key
        // see how numbers 1 to 125 can be generated
        x = rand5() + 5 * (rand5() - 1) + 5 * 5 * (rand5() - 1);
    }

    return (x % 7) + 1;
}

int main()
{
    srand(1);

    int result[7];
    for (int i = 0; i < 7; ++i)
    {
        result[i] = 0;
    }
    
    int i = 100000;
    while (i--)
    {
        int k = rand7()-1;
        if (k < 0 || k > 6) std::cout << "error: " << k << std::endl;
        result[rand7()-1]++;
    }

    int sum = 0;
    for (int i = 0; i < 7; ++i)
    {
        std::cout << i+1 << ": " << result[i] << std::endl;
        sum += result[i];
    }

    std::cout << "total: " << sum << std::endl;
    
    return 0;
}

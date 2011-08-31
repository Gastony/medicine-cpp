#include <iostream>
using namespace std;

#include <vector>

void swap(std::vector<int> & data, int i, int j)
{
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void print(std::vector<int> const & data)
{
    std::vector<int>::const_iterator iter = data.begin();

    for (; iter != data.end(); ++iter)
    {
        cout << *iter << " ";
    }

    if (data.size() > 0)
    {
        cout << endl;
    }
}

void Shuffle(std::vector<int> & data)
{
    int length = data.size();

    for (int i = 0; i < length; ++i)
    {
        swap(data, i, generateRandom(i+1, length-1));
    }

    print(data);
}

int generateRandom(int low, int high)
{
}

//useful for small lists, and for large lists where data is
//already sorted
void BubbleSort(std::vector<int> & data)
{
    int length = data.size();

    for (int i = 0; i < length; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < length - (i+1); ++j)
        {
            if (data[j] > data[j+1])
            {
                swap(data, j, j+1);
                swapped = true;
            }
        }
        
        if (!swapped) break;
    }
}

//useful for small lists and where swapping is expensive
// does at most n swaps
void SelectionSort(std::vector<int> & data)
{
}

int main()
{
    int a[] = {5, 6, 1, 2, 0, 8};
    std::vector<int> data(a, a + sizeof(a)/sizeof(int));

    //bubble sort
    BubbleSort(data);
    print(data);

    //selection sort
    Shuffle(data);
    SelectionSort(data);
    print(data);
    
    return 0;
}

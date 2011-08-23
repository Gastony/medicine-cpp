#include <iostream>
using namespace std;

// for operator overloading, atleast one of the operand has to be user
// defined

class Matrix
{
public:
    Matrix(int row, int col) : rows(row), cols(col)
        { data = new int[rows * cols];}
    ~Matrix() { delete [] data; }
    int & operator() (int row, int col);
    int operator() (int row, int col) const;
    int operator++ (int notUsed);
    int & operator++();
private:
    int rows;
    int cols;
    int * data;
};

int & Matrix::operator() (int row, int col)
{
    return data[row*col + col];
}

int Matrix::operator() (int row, int col) const
{
    return data[row*col + col];
}

int Matrix::operator++ (int notUsed)
{
    int tmp = data[3*2 + 2];
    data[3*2 + 2] += 2;
    return tmp;
}

int & Matrix::operator++ ()
{
    data[3*2 + 2] += 3;
    return data[3*2 + 2];
}


int main()
{
    Matrix m(4,4);
    m(3,2) = 5;

    cout << "element at 3,2 is " << m(3,2) << "\n";

    cout << "element at 3,2 is " << m++ << "\n";

    cout << "element at 3,2 is " << ++m << "\n";
    
    return 0;
}

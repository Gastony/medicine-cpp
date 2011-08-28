#include <iostream>
using namespace std;

class Matrix
{
public:
  Matrix(int rows, int cols);
  ~Matrix();
  bool find(int val);
  void print();
private:
  int * data;
  int rows;
  int cols;
};

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
  data = new int[rows * cols];

  int counter = 0;
  for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
	{
	  data[rows * i + j] = counter++;
	}
    }
}

Matrix::~Matrix()
{
  delete [] data;
}

void Matrix::print()
{
for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
	{
	  cout << data[rows * i + j] << " ";
	}
      cout << endl;
    }
}

bool Matrix::find(int val)
{
  int nrow = rows-1, ncol = 0;

  int mval = 0;
  while(nrow >= 0 && ncol < cols)
    {
      mval = data[nrow * cols + ncol];
      cout << mval << endl;
      if (mval == val)
	{
	  cout << "found " << val << " at (" << nrow << "," << " " << ncol << ")" << endl;
	  return true;
	}
      else if (val > mval)
	{
	  ++ncol;
	}
      else
	{
	  --nrow;
	}
    }

  cout << "not found " << val << endl;

  return false;
}

int main()
{

  Matrix m(4,4);
  m.print();

  m.find(3);
  m.find(15);
  m.find(20);
  m.find(0);

  return 0;
}

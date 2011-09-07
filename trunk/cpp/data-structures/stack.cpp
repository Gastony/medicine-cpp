#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <class T>
class Stack
{
public:
  Stack() {}
  void push(T x);
  void pop();
  T & top();
  size_t size();
  bool empty();
private:
  std::vector<T> elems;
};

template <class T>
void Stack<T>::push(T x)
{
  elems.push_back(x);
}

template <class T>
void Stack<T>::pop()
{
  if (elems.size() > 0)
    {
      elems.erase(elems.end() - 1);
    };
}

template <class T>
T & Stack<T>::top()
{
  assert(elems.size() > 0);
  return elems.at(elems.size()-1);
}

template <class T>
size_t Stack<T>::size()
{
  return elems.size();
}

template <class T>
bool Stack<T>::empty()
{
  return elems.size() == 0 ? true : false;
}

int main()
{

  Stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4); 
  s.push(5);

  cout << "size: " << s.size() << endl;
  cout << "top element: " << s.top() << endl;

  s.pop();
  s.pop();

  cout << "size: " << s.size() << endl;
  cout << "top element: " << s.top() << endl;
  cout << "empty: " << s.empty() << endl;

  s.pop();
  s.pop();
  s.pop();

  cout << "size: " << s.size() << endl;
  //cout << "top element: " << s.top() << endl;
  cout << "empty: " << s.empty() << endl;

  return 0;
}



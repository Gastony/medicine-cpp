#include <iostream>
#include <list>
using namespace std;

template <class T>
class Queue
{
public:
  void push(T x);
  void pop();
  T & front();
  T & back();
  bool empty();
  size_t size();
private:
  std::list<T> elems;
};

template <class T>
void Queue<T>::push(T x)
{
  elems.push_back(x);
}

template <class T>
void Queue<T>::pop()
{
  elems.pop_front();
}

template <class T>
T & Queue<T>::front()
{
  return elems.front();
}

template <class T>
T & Queue<T>::back()
{
  return elems.back();
}

template <class T>
bool Queue<T>::empty()
{
  return elems.size() == 0;
}

template <class T>
size_t Queue<T>::size()
{
  return elems.size();
}

int main()
{
  Queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  cout << "size: " << q.size() << endl;
  cout << "first: " << q.front() << " back:" << q.back() << endl;

  q.pop();
  q.pop();
  
  cout << "size: " << q.size() << endl;
  cout << "first: " << q.front() << " back:" << q.back() << endl;

  q.pop();
  q.pop();
  cout << "empty: " << q.empty() << endl;

  return 0;
}

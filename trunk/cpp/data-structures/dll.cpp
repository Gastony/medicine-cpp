#include <iostream>
using namespace std;

template <class T>
struct Node
{
  Node(T data) : data(data), next(NULL), prev(NULL) {}
  T data;
  Node * next;
  Node * prev;
};

template <class T>
class DoublyLinkedList
{
public:
  DoublyLinkedList() : head(NULL), tail(NULL) {}
  DoublyLinkedList(const DoublyLinkedList<T> & dll);
  ~DoublyLinkedList();
  void addNode(T data);
  //void insertNodeBefore(int data, int before);
  //void insertNodeAfter(int data, int after);
  void deleteNode(T data);
  template <class U>
  friend std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll);
private:
  Node<T> * head;
  Node<T> * tail;
};

template <class U>
std::ostream & operator<<(std::ostream & os, const DoublyLinkedList<U> & dll)
{
  Node<U> * tmp = dll.head;
  while (tmp)
    {
      os << tmp->data << " ";
      tmp = tmp->next;
    }

  return os;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  Node<T> * tmp = NULL;
  while (head)
    { 
      tmp = head;
      head = head->next;
      delete tmp;
    }
  head = tail = NULL;
}

template <class T>
void DoublyLinkedList<T>::addNode(T data)
{
  Node<T> * t = new Node<T>(data);
  
  Node<T> * tmp = head;
  if (tmp == NULL)
    {
      head = tail = t;
    }
  else
    {
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}

      tmp->next = t;
      t->prev = tail;

      tail = t;
    }
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T data)
{
  Node<T> * tmp = head;
  while (tmp && tmp->data != data)
    {
      tmp = tmp->next;
    }

  if (tmp)
    {
      if (tmp->prev && tmp->next) // no change to head or tail
	{
	  tmp->prev->next = tmp->next;
	  tmp->next->prev = tmp->prev;
	}
      else if (tmp->prev) // change to tail
	{
	  tmp->prev->next = tmp->next;
	  tail = tmp->prev;
	}
      else if (tmp->next) // change to head
	{
	  tmp->next->prev = tmp->prev;
	  head = tmp->next;
	}

      delete tmp;
    }
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> & dll)
{
  Node<T> * tmp = dll.head;
  while (tmp)
    {
      this->addNode(tmp->data);
      tmp = tmp->next;
    }
}

int main()
{
  DoublyLinkedList<int> dll;

  dll.addNode(1);
  dll.addNode(2);
  dll.addNode(3);
  dll.addNode(4);
  dll.addNode(5);

  cout << dll << endl;
  DoublyLinkedList<int> dll2(dll);
  cout << dll2 << endl;

  dll.deleteNode(3);
  dll.deleteNode(1);
  dll.deleteNode(5);

  cout << dll << endl;
  cout << dll2 << endl;

  return 0;
}

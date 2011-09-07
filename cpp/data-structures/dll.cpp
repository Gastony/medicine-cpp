#include <iostream>
using namespace std;

struct Node
{
  Node(int data) : data(data), next(NULL), prev(NULL) {}
  int data;
  Node * next;
  Node * prev;
};

class DoublyLinkedList
{
public:
  DoublyLinkedList() : head(NULL), tail(NULL) {}
  DoublyLinkedList(const DoublyLinkedList & dll);
  ~DoublyLinkedList();
  void addNode(int data);
  //void insertNodeBefore(int data, int before);
  //void insertNodeAfter(int data, int after);
  void deleteNode(int data);
  friend std::ostream & operator<<(std::ostream & os, const DoublyLinkedList & dll);
private:
  Node * head;
  Node * tail;
};

std::ostream & operator<<(std::ostream & os, const DoublyLinkedList & dll)
{
  Node * tmp = dll.head;
  while (tmp)
    {
      os << tmp->data << " ";
      tmp = tmp->next;
    }

  return os;
}

DoublyLinkedList::~DoublyLinkedList()
{
  Node * tmp = NULL;
  while (head)
    { 
      tmp = head;
      head = head->next;
      delete tmp;
    }
  head = tail = NULL;
}

void DoublyLinkedList::addNode(int data)
{
  Node * t = new Node(data);
  
  Node * tmp = head;
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

void DoublyLinkedList::deleteNode(int data)
{
  Node * tmp = head;
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

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList & dll)
{
  Node * tmp = dll.head;
  while (tmp)
    {
      this->addNode(tmp->data);
      tmp = tmp->next;
    }
}

int main()
{
  DoublyLinkedList dll;

  dll.addNode(1);
  dll.addNode(2);
  dll.addNode(3);
  dll.addNode(4);
  dll.addNode(5);

  cout << dll << endl;
  DoublyLinkedList dll2(dll);
  cout << dll2 << endl;

  dll.deleteNode(3);
  dll.deleteNode(1);
  dll.deleteNode(5);

  cout << dll << endl;
  cout << dll2 << endl;

  return 0;
}

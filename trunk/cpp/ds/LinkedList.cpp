#include <iostream>

struct Node
{
  int data;
  Node * next;
};

class LinkedList
{
public:
  LinkedList() : head(NULL) {};
  ~LinkedList() { destroyList(); };
  bool addNode(int data);
  bool deleteNode(int data);
  Node * searchNode(int data);
  void printList();
  void reverseList();
  void recursiveReverseList();
private:
  Node * head;
  void destroyList();
};

bool LinkedList::addNode(int data)
{
try
  {
    Node * tmp = new Node();
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return true;
  }
catch(std::exception & ex)
  {
    return false;
  }
}

bool LinkedList::deleteNode(int data)
{
  Node *curr = head, *prev = NULL;

  while (curr)
  {
    if (curr->data == data) break;
    
    prev = curr;
    curr = curr->next;
  }

  if (curr)
    {
      if (prev)
	{
	  prev->next = curr->next;
	}
      else
	{
	  head = curr->next;
	}
      delete(curr);
      return true;
    }
  else
    {
      return false;
    }
}

Node * LinkedList::searchNode(int data)
{
  Node * tmp = head;
  while (tmp)
    {
      if (tmp->data == data)
	{
	  return tmp;
	}
      tmp = tmp->next;
    }
  return NULL;
}

void LinkedList::printList()
{
  Node * tmp = head;
  bool printNewLine = (tmp) ? true : false;
  while (tmp)
    {
      std::cout << tmp->data << "|";
      tmp = tmp->next;
    } 

  if (printNewLine)
    {
      std::cout << std::endl;
    }
}

void LinkedList::destroyList()
{
  Node * tmp = NULL;
  while (head)
    {
      tmp = head;
      head = head->next;
      std::cout << "deleting data " << tmp->data << std::endl;
      delete(tmp);
    }
}

void LinkedList::reverseList()
{
  Node *curr = head, *prev = head, *save = NULL;

  while (curr)
    {
      save = curr->next;
      curr->next = prev;
      prev = curr;
      curr = save;
    }

  head->next = NULL;
  head = prev;
}

void LinkedList::recursiveReverseList()
{
}

int main()
{
  LinkedList l;
  l.addNode(3);
  l.addNode(2);
  l.addNode(6);
  l.addNode(4);
  l.addNode(3);

  l.printList();
  l.reverseList();
  l.printList();

  l.deleteNode(3);
  l.deleteNode(3);
  l.deleteNode(4);
  
  l.printList();
  l.reverseList();
  l.printList();

  if (l.searchNode(2))
    {
      std::cout << "2 found \n";
    }

  if (!l.searchNode(5))
    {
      std::cout << "5 not found \n";
    }
  return 0;
}
  

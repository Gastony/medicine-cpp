#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node * next;
  Node(int data) : data(data), next(NULL) {}
};

class CircularLinkedList
{
public:
  CircularLinkedList() : head(NULL) {}
  ~CircularLinkedList();
  void addNode(int data);
  void deleteNode(int data);
  friend std::ostream & operator<<(std::ostream & os, const CircularLinkedList & cll);
private:
  Node * head;
};

CircularLinkedList::~CircularLinkedList()
{
}
void CircularLinkedList::addNode(int data)
{
}

void CircularLinkedList::deleteNode(int data)
{
}

std::ostream & operator<<(std::ostream & os, const CircularLinkedList & cll)
{
}

int main()
{
  CircularLinkedList cll;

  cll.addNode(1);
  cll.addNode(2);
  cll.addNode(3);
  cll.addNode(4);
  cll.addNode(5);

  cout << cll << endl;
  
  cll.deleteNode(3);
  cll.deleteNode(1);
  cll.deleteNode(5);

  cout << cll << endl;

  return 0;
}

#include <iostream>
using namespace std;

#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

class Edge
{
public:
  int dest;
  int weight;

  Edge(int dest) : dest(dest), weight(0) {}
};

class Vertex
{
public:
  int orig;
  std::list<Edge> adjList;
  bool visited;

  Vertex(int v) : orig(v), visited(false) {}
  friend bool operator==(const Vertex & v, int data);
  friend std::ostream & operator<<(std::ostream & os, const Vertex & v);
};

bool operator==(const Vertex & v, int data)
{
  if (v.orig == data) return true;
  return false;
}

std::ostream & operator<<(std::ostream & os, const Vertex & v)
{
  os << v.orig << ":";
  std::list<Edge>::const_iterator iter = v.adjList.begin();
  for(; iter != v.adjList.end(); ++iter)
    {
      os << " " << iter->dest;
    }

  return os;
}

class Graph
{
private:
  std::vector<Vertex> vertices;
public:
  void addVertex(int v);
  void addEdge(int v1, int v2);
  void print();
  void BreadthFirstTour(int v);
  void DepthFirstTour(int v);
  void TopologicalSort();
};

void Graph::addVertex(int v) 
{
  vertices.push_back(v); //implicit constructor call
}

void Graph::addEdge(int v1, int v2)
{
  std::vector<Vertex>::iterator iter = find(vertices.begin(), vertices.end(), v1);
  if (iter != vertices.end())
    {
      Edge edge(v2);
      iter->adjList.push_back(edge);
    }
}

void Graph::print()
{
  std::vector<Vertex>::const_iterator iter = vertices.begin();
  for (; iter != vertices.end(); ++iter)
    {
      cout << *iter << "\n";
    }
}

void Graph::BreadthFirstTour(int v)
{
  cout << "BFS BEGIN\n";

  std::queue<int> q;
  std::vector<Vertex>::iterator iter = find(vertices.begin(), vertices.end(), v);
  if (iter != vertices.end())
    {
      q.push(iter-vertices.begin());
    }
  else
    {
      cout << "BFS END\n";
      return;
    }

  while (!q.empty())
    {
      int vtx = q.front();
      q.pop();
      if (vertices[vtx].visited == false)
	{
	  vertices[vtx].visited = true;
	  cout << vertices[vtx].orig << " ";

	  std::list<Edge>::const_iterator iter = vertices[vtx].adjList.begin();
	  while (iter != vertices[vtx].adjList.end())
	    {
	      //cout << "dest " << iter->dest << endl;
	      std::vector<Vertex>::const_iterator citer = find(vertices.begin(), vertices.end(), iter->dest);
	      if (citer != vertices.end())
		{
		  q.push(citer-vertices.begin());
		  //cout << "pushing " << citer->orig << endl;
		}
	      ++iter;
	    }
	}
    }

  cout << "\nBFS END" << endl;
}

void Graph::DepthFirstTour(int v)
{
  cout << "DFS START\n";
  cout << "\nDFS END" << endl;
}

void Graph::TopologicalSort()
{
}

int main()
{
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.print();

    g.BreadthFirstTour(1);
    
    g.DepthFirstTour(1);

    return 0;
}


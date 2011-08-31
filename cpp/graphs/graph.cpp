#include <iostream>
using namespace std;

#include <list>
#include <queue>
#include <map>

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
    int indegree;
    
    Vertex() : orig(-1), visited(false), indegree(0) {}
    Vertex(int v) : orig(v), visited(false), indegree(0) {}
    
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
    typedef std::map<int, Vertex> VertexMap;
    typedef std::map<int, Vertex>::iterator VertexIterator;
    typedef std::map<int, Vertex>::const_iterator VertexConstIterator;
    bool visit(int v, std::list<int> & sortedList);
        
    VertexMap vertices;
public:
    void addVertex(int v);
    void addEdge(int v1, int v2);
    void print();
    void BreadthFirstTour(int v);
    void DepthFirstTour(int v);
    void TopologicalSort();
    void resetStates();
};

void Graph::addVertex(int v) 
{
  vertices.insert( std::make_pair(v, Vertex(v)) );
}

void Graph::addEdge(int v1, int v2)
{
    VertexIterator iter = vertices.find(v1);

    if (iter != vertices.end())
    {
        Edge edge(v2);
        iter->second.adjList.push_back(edge);
    }

    iter = vertices.find(v2);
    iter->second.indegree++;
}

void Graph::print()
{
    VertexConstIterator iter = vertices.begin();
    for (; iter != vertices.end(); ++iter)
    {
        cout << iter->second << "\n";
    }
}

void Graph::BreadthFirstTour(int v)
{
  cout << "BFS BEGIN\n";

  std::queue<int> q;
  VertexConstIterator iter = vertices.find(v);
  if (iter != vertices.end())
  {
      q.push(iter->first);
  }
  else
  {
      cout << "BFS END\n";
      return;
  }

  VertexIterator iter1;
  while (!q.empty())
  {
      int vtx = q.front();
      q.pop();

      Vertex & v = vertices[vtx];
      if (v.visited == false )
      {
          v.visited = true;
          cout << v.orig << " ";

          std::list<Edge>::const_iterator iter = v.adjList.begin();
          while (iter != v.adjList.end())
            {
                //cout << "dest " << iter->dest << endl;
                VertexConstIterator citer = vertices.find(iter->dest);
                if (citer != vertices.end())
                {
                    q.push(citer->first);
                    //cout << "pushing " << citer->orig << endl;
                }
                ++iter;
            }
      }
  }
  
  cout << "\nBFS END" << endl;
  
  resetStates();
}

void Graph::resetStates()
{
    VertexIterator iter = vertices.begin();
    for (; iter != vertices.end(); ++iter)
    {
        iter->second.visited = false;
    }
}

void Graph::DepthFirstTour(int v)
{
    VertexIterator iter = vertices.find(v);
    if (iter != vertices.end())
    {
        if (iter->second.visited == false)
        {
            iter->second.visited = true;
            
            std::list<Edge>::iterator liter = iter->second.adjList.begin();
            for (; liter != iter->second.adjList.end(); ++liter)
            {
                DepthFirstTour(liter->dest);
            }
            
            cout << iter->second.orig << " ";
        }
    }
}

void Graph::TopologicalSort()
{
    VertexConstIterator iter = vertices.begin();
    std::list<int> sortedList;
    bool cycle = false;
    for (; iter != vertices.end(); ++iter)
    {
        if (iter->second.indegree == 0) 
        {
            if (!visit(iter->first, sortedList))
            {
                cycle = true;
                break;
            }
        }
    }

    if (cycle || sortedList.size() != vertices.size())
    {
        cout << "CYCLE";
        return;
    }
    
    std::list<int>::const_iterator liter = sortedList.begin();
    for (; liter != sortedList.end(); ++liter)
    {
        cout << *liter << " ";
    }
}

bool Graph::visit(int v, std::list<int> & sortedList)
{
    VertexIterator iter = vertices.find(v);
    if (iter != vertices.end())
    {
        if (iter->second.visited == false)
        {
            iter->second.visited = true;

            std::list<Edge>::const_iterator liter = iter->second.adjList.begin();
            for (; liter != iter->second.adjList.end(); ++liter)
            {
                if (!visit(liter->dest, sortedList))
                {
                    return false;
                }
            }
            sortedList.push_front(iter->first);
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Graph g;

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(3,7);
    //g.addEdge(5,8); //disjoint node 8

    //g.addEdge(6,3); //this is forming cycle

    g.print();

    g.BreadthFirstTour(1);

    cout << "DFS START\n";
    g.DepthFirstTour(1);
    g.resetStates();
    cout << "\nDFS END" << endl;

    cout << "TOPOLOGICAL SORT START\n";
    g.TopologicalSort();
    g.resetStates();
    cout << "\nTOPOLOGICAL SORT END\n";
    
    return 0;
}

#include <iostream>
using namespace std;

#include <vector>
#include <queue>

class Edge;

class Vertex
{
private:
    int v;
    bool visited;
public:
    int getVal() const { return v; } 

    explicit Vertex(int v) : v(v), visited(false) {}

    bool isVisited() { return visited; }

    void setVisited(bool flag) { visited = flag; }
};

class Edge
{
private:
    int cost;
    const Vertex & dest;
public:
    explicit Edge(const Vertex & dest) :  dest(dest), cost(0) {}
    const Vertex & getDest() const { return dest; }
};

bool operator< (const Vertex & v1, const Vertex & v2)
{
    return v1.v < v2.v;
}

class Graph
{
public:
    void addVertex(int v);
    void addEdge(int v1, int v2);
    void print();
    void BreadthFirstTour(int v);
    void DepthFirstTour(int v);
    void TopologicalSort();
    
private:
    std::map<Vertex, std::list<Edge>, std::less<Vertex> > vertices;
};

void Graph::addVertex(int v) 
{
    std::map<Vertex, std::list<Edge> >::iterator iter = vertices.find(Vertex(v));
    if (iter == vertices.end())
    {
        std::list<Edge> el;
        vertices.insert(std::make_pair(Vertex(v), el));
    }
}

void Graph::addEdge(int v1, int v2)
{
    std::map<Vertex, std::list<Edge> >::iterator iter2 = vertices.find(Vertex(v2));
    if (iter2 == vertices.end()) return;

    std::map<Vertex, std::list<Edge> >::iterator iter = vertices.find(Vertex(v1));
    if (iter == vertices.end()) return;

    iter->second.push_back(Edge(iter2->first));
}

void Graph::print()
{
    std::map<Vertex, std::list<Edge> >::const_iterator iter = vertices.begin();

    for (; iter != vertices.end(); ++iter)
    {
        cout << iter->first.getVal() << " :";

        std::list<Edge>::const_iterator liter = iter->second.begin();
        for (; liter != iter->second.end(); ++liter)
        {
            cout << " " << liter->getDest().getVal();
        }
        cout << "\n";
    }
}

void Graph::BreadthFirstTour(int v)
{
    cout << "Starting BFS\n";

    std::queue<const Vertex &> q;
    q.push(Vertex(v));

    while (!q.empty())
    {
        
    }
    
    cout << "Ending BFS" << std::endl;
}

void Graph::DepthFirstTour(int v)
{
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

    g.print();

    g.BreadthFirstTour(1);
    
    return 0;
}


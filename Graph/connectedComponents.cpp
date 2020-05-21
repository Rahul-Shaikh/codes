#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool* visited);
    public:
    Graph(int v);
    void components();
    void addEdge(int v, int w);
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool *visited)
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end(); itr++)
    {
        if (!visited[*itr]) DFSUtil(*itr, visited);
    }
}

void Graph::components()
{
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++) visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFSUtil(i, visited);
            printf("\n");
        }
    }
}

int main(void)
{
    Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 

    cout << "Following are connected components \n"; 
    g.components(); 

    return 0; 
    return 0;
}
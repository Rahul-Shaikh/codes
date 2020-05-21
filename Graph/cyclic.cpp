#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool *visited, bool *recStack);

    public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int v)
{
    V = v;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool *visited, bool *recStack)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator itr;
        for (itr = adj[v].begin(); itr != adj[v].end(); itr++)
        {
            if (!visited[*itr] && isCyclicUtil(*itr, visited, recStack))
            {
                return true;
            }
            else if (recStack[*itr])
            {
                return true;
            }
        }

    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (isCyclicUtil(i, visited, recStack)) return true;
    }
    return false;
}

int main(void)
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2);  
    g.addEdge(2, 3); 
    g.addEdge(1, 3); 

    if(g.isCyclic()) 
        cout << "Graph contains cycle\n"; 
    else
        cout << "Graph doesn't contain cycle\n"; 
    return 0; 
}
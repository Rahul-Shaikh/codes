#include <iostream>
#include <list>

using namespace std;

class Graph
{
  int v;
  list<int> *adj;

public:
  Graph(int V);
  void addEdge(int v, int w);
  void BFS(int s);
  void DFS(int s);
};

Graph::Graph(int v)
{
  this->v = v;
  adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w);
}

void Graph::BFS(int s)
{
  bool *visited = new bool[v];

  for (int i = 0; i < v; i++)
  {
    visited[i] = false;
  }

  list<int> queue;

  visited[s] = true;
  queue.push_back(s);

  while(!queue.empty())
  {
    s = queue.front();
    cout << s << " ";
    queue.pop_front();

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

void Graph::DFS(int s)
{
  bool *visited = new bool[v];

  for (int i = 0; i < v; i++) visited[i] = false;

  list<int> stack;

  visited[s] = true;
  stack.push_back(s);

  while(!stack.empty())
  {
    s = stack.back();
    cout << s << " ";

    stack.pop_back();

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); i++)
    {
      if (!visited[*i])
      {
        visited[*i] = true;
        stack.push_back(*i);
      }
    }
  }

}

int main(void)
{
  Graph g(7);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);


  cout << "BFS: ";
  g.BFS(2 );
  cout << endl;
  cout << "DFS: ";
  g.DFS(2);
  cout << endl;

}

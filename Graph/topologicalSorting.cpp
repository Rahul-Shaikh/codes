#include <cstring>
#include <iostream>
#include <list>

using namespace std;

class Graph {
  int V;
  list<int> *adj;
  void topologicalSortUtil(int i, bool *visited, list<int> &stack);

 public:
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void topologicalSort();
};

void Graph::topologicalSort() {
  bool visited[V];
  memset(visited, 0, sizeof(V));

  list<int> stack;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) topologicalSortUtil(i, visited, stack);
  }

  while (!stack.empty()) {
    cout << stack.back() << " ";
    stack.pop_back();
  }
  cout << endl;
}

void Graph::topologicalSortUtil(int i, bool *visited, list<int> &stack) {
  visited[i] = true;

  for (auto v : adj[i])
    if (!visited[v]) topologicalSortUtil(v, visited, stack);

  stack.push_back(i);
}

int main(void) {
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  cout << "Following is a Topological Sort of the given graph \n";
  g.topologicalSort();

  return 0;
}

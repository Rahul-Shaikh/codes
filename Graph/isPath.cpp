#include <iostream>
#include <list>

using namespace std;

class Graph {
  int V;
  list<int> *adj;

 public:
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }

  void addEdge(int u, int v) { adj[u].push_back(v); }

  bool isReachable(int s, int d) {
    list<int> queue;
    bool visited[V];

    memset(visited, 0, sizeof(visited));

    queue.push_back(s);
    visited[s] = true;

    while (!queue.empty()) {
      int v = queue.front();
      queue.pop_front();

      for (auto &itr : adj[v]) {
        if (itr == d) return true;
        if (!visited[itr]) {
          visited[itr] = true;
          queue.push_back(itr);
        }
      }
    }
    return false;
  }
};

int main(void) {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  int u = 1, v = 3;
  if (g.isReachable(u, v))
    cout << "\n There is a path from " << u << " to " << v;
  else
    cout << "\n There is no path from " << u << " to " << v;

  u = 3, v = 1;
  if (g.isReachable(u, v))
    cout << "\n There is a path from " << u << " to " << v;
  else
    cout << "\n There is no path from " << u << " to " << v;

  return 0;
}

#include <climits>
#include <iostream>
#include <list>
#include <queue>

using namespace std;
typedef pair<int, int> ii;  // (w, v)

class Graph {
  int V;
  list<ii> *adj;

  void printPath(vector<int> parent, int j) {
    if (parent[j] == -1) return;

    printPath(parent, parent[j]);
    printf("%d ", j);
  }

 public:
  Graph(int V) {
    this->V = V;
    adj = new list<ii>[V];
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(w, v));
    adj[v].push_back(make_pair(w, u));
  }

  void shortestPath(int s) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V);

    parent[s] = -1;
    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      for (auto &itr : adj[u]) {
        int v = itr.second;
        int w = itr.first;

        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          pq.push(make_pair(dist[v], v));
          parent[v] = u;
        }
      }
    }

    cout << "vertex \t\t distance \t\t path: " << endl;
    for (int i = 0; i < V; i++) {
      cout << i << " \t\t " << dist[i] << " \t\t\t " << s << " ";
      printPath(parent, i);
      cout << endl;
    }
  }
};
int main(void) {
  Graph g(9);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  g.shortestPath(0);
}

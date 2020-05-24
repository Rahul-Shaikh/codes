#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

class Graph {
  int V;
  list<ii> *adj;

 public:
  Graph(int V) {
    this->V = V;
    adj = new list<ii>[V];
  }

  void addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(w, v));  // weight is in the first part as
                                        // default comparison is done by first
    adj[v].push_back(make_pair(w, v));
  }

  void shortestDistance(int s);
};

void Graph::shortestDistance(int s) {
  priority_queue<ii, vector<ii>, greater<ii> > pq;

  vector<int> dist(V, INT_MAX);

  pq.push(make_pair(0, s));
  dist[s] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &i : adj[u]) {  // getting all adjacents

      int v = i.second;  // current adjacent vertex
      int w = i.first;

      if (dist[v] >
          dist[u] +
              w)  // if the distance from source is less by going through u
      {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  cout << "Vertex Distance from the source\n";
  for (int i = 0; i < V; i++) {
    cout << i << "\t\t " << dist[i] << endl;
  }
}

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

  g.shortestDistance(0);
}

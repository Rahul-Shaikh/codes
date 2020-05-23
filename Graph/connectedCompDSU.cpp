#include <iostream>

using namespace std;

class DisjSet {
  int *rank, *parent, n;

public:
  DisjSet(int n);

  void makeSet();
  int find(int x);
  void _union(int x, int y);

//  ~DisjSet();
};

DisjSet::DisjSet(int n){
  this->n = n;
  rank = new int[n];
  parent = new int[n];
  this->makeSet();
}

void DisjSet::makeSet()
{
  for (int i = 0; i < n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

// Path Compression
int DisjSet::find(int x){
  
  if (parent[x] != x){
    parent[x] = find(parent[x]);
  }

  return parent[x];
}

// Rank method
void DisjSet::_union(int x, int y){

  int xset = find(x);
  int yset = find(y);

  if (xset == yset) return;

  if (rank[xset] > rank[yset]){
    parent[yset] = xset;
  }

  else if (rank[yset] > rank[xset]){
    parent[xset] = yset;
  }

  else {
    parent[yset] = xset;
    rank[xset]++;
  }

}

class Edge
{
public:
  int v1, v2;
};

class Graph {
  
  int V, E;

public:
  Graph(int V, int E);
  Edge *edges;
  
  bool isCycle()
  {
    DisjSet dsu(V);
    
    for (int i = 0; i < E; i++)
    {
      int x = dsu.find(edges[i].v1);
      int y = dsu.find(edges[i].v2);

      if (x == y) return true;

      dsu._union(x, y);
    }
    return false;
  }

};


Graph::Graph(int V, int E){
  this->V = V;
  this->E = E;
  
  edges = new Edge[E];
  
}
int main(void)
{
  Graph g(3, 2);

  g.edges[0].v1 = 0;
  g.edges[0].v2 = 1;

  g.edges[1].v1 = 1;
  g.edges[1].v2 = 2;

  //g.edges[2].v1 = 0;
  //g.edges[2].v2 = 2;

//  for (int i = 0; i < 3; i++)
//  {
//    cout << g.edges[i].v1 << " " << g.edges[i].v2 << endl;
//  }

  if (g.isCycle()) cout << "Graph contains cycle\n";
  else cout << "Graph doesn't contain cycle\n";

  return 0;
}

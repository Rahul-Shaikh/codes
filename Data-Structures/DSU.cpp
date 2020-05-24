#include <iostream>
#include <list>

using namespace std;

class DisjSet {
  int N, *rank, *parent;

  void makeSet() {
    for (int i = 0; i < N; i++) {
      rank[i] = 0;
      parent[i] = i;
    }
  }

 public:
  DisjSet(int N) {
    this->N = N;
    rank = new int[N];
    parent = new int[N];
    makeSet();
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // compressing path
    }
    return parent[x];
  }

  void _union(int x, int y) {
    int xset = find(x);
    int yset = find(y);

    if (xset == yset) return;

    if (rank[xset] > rank[yset])
      parent[yset] = xset;

    else if (rank[yset] > rank[xset])
      parent[xset] = yset;

    else {
      parent[yset] = xset;
      rank[xset]++;
    }
  }
};

int main(void) {
  DisjSet dsu(10);  // {0, 1, 2, 3, 4}, {5, 6}, {8, 9}, {7}

  dsu._union(0, 1);
  dsu._union(1, 2);
  dsu._union(2, 3);
  dsu._union(3, 4);

  dsu._union(5, 6);
  dsu._union(8, 9);

  list<pair<int, list<int> > > lists;

  for (int i = 0; i < 10; i++) {
    int parent = dsu.find(i);
    cout << i << " " << parent << endl;
    bool flag = true;
    for (auto &itr : lists) {
      if (itr.first == parent) {
        itr.second.push_back(i);
        flag = false;
        break;
      }
    }
    if (flag) lists.push_back(make_pair(parent, list<int>()));
  }

  for (auto &list : lists) {
    cout << "set " << list.first << " is : " << list.first << " ";
    for (auto &itr : list.second) cout << itr << " ";
    cout << endl;
  }
}

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int nodes, edges;
	cin >> nodes;
	cin >> edges;

	vector<int> adj[nodes+1];

	for (int i = 0; i < edges; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	for (int i = 0; i <= nodes; i++)
	{
		cout << i << " : ";
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (j == adj[i].size()-1) cout << adj[i][j];
			else cout << adj[i][j] << " --> ";
		}
		cout << endl;
	}
}
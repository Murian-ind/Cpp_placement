#include <bits/stdc++.h>
using namespace std;

int main()
{
	// n = no of nodes
	// e = no of edges
	int n, e;
	cout << "No of node: ";
	cin >> n;
	cout << "No of edges: ";
	cin >> e;

	// declare the adjacent matrix
	vector<int> adj[n];

	// take edges as input
	cout << "Provide 'e' lines of nodes connection : " << endl;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0;i<n;i++){
		cout<<i<<" -> ";
		for(auto j:adj[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	return 0;
}
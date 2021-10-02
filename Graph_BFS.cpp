#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int n, vector<int> adj[])
{
	vector<int> bfs;
	vector<int> vis(n, 0);
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	while (!q.empty())
	{
		int i = q.front();
		q.pop();
		bfs.push_back(i);

		for (auto j : adj[i])
		{
			if (!vis[j])
			{
				q.push(j);
				vis[j] = 1;
			}
		}
	}

	return bfs;
} 

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


	cout << "BFS: ";
	vector<int> ans = bfsOfGraph(n, adj);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}
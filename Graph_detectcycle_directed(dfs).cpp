#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int c,vector<int> &dfsvis,vector<int> &vis,vector<int> adj[] ){
    vis[c]=1;
    dfsvis[c]=1;
    for(auto i:adj[c]){
       if(vis[i]==0){
            if(checkCycle(i,dfsvis,vis,adj))
            return true;
       }
       else if(vis[i]==1 && dfsvis[i]==1){
        return true;
       }
    }
    dfsvis[c]=0;
    return false;
}


int main(){
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
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bool isCycleDetected=false;
    vector<int> vis(n,0);
    vector<int> dfsvis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(checkCycle(i,dfsvis,vis,adj)){
                isCycleDetected=true;
            }
        }
    }
    if(isCycleDetected)
    cout<<"cycle present";
    else
    cout<<"cycle not present";

    return 0;
}
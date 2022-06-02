#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void topo(int i,vector<int>&visited,vector<int>adj[],stack<int>&s)
	{
	    visited[i]=1;
	    for(auto j:adj[i])
	    {
	        if(!visited[j])
	        {
	            topo(j,visited,adj,s);
	        }
	    }
	    s.push(i);
	}
	vector<int> topoSort(int n, vector<int> adj[])
	{
	   vector<int>v;
	   stack<int>s;
	   vector<int>visited(n,0);
	   for(int i=0;i<n;i++)
	   {
	       if(!visited[i])
	       {
	           topo(i,visited,adj,s);
	       }
	   }
	   while(!s.empty())
	   {
	       v.push_back(s.top());
	       s.pop();
	   }
	   return v;
	}
};


int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}  

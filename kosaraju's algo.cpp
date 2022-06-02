#include<bits/stdc++.h>
using namespace std;




class Solution
{
	public:

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
	void dfs(int i,vector<int>&visited,vector<int>adj[])
	{
	    visited[i]=1;
	    for(auto j:adj[i])
	    {
	        if(!visited[j])
	        {
	            dfs(j,visited,adj);
	        }
	    }
	}
    int kosaraju(int n, vector<int> adj[])
    {
       vector<int>res[n];
       for(int i=0;i<n;i++)
       {
           for(auto j:adj[i])
           {
               res[j].push_back(i);
           }
       }
       vector<int>visited(n,0);
       stack<int>s;
       for(int i=0;i<n;i++)
       {
           if(!visited[i])
           {
               topo(i,visited,adj,s);
           }
       }
       int count=0;
       vector<int>vis(n,0);
       while(!s.empty())
       {
           if(!vis[s.top()])
           {
               dfs(s.top(),vis,res);
               count++;
           }
           s.pop();
       }
       return count;
    }
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

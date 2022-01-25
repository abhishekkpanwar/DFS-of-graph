DFS-of-graph

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int i,vector<int>&visited,vector<int>adj[],vector<int>&v)
    {
        visited[i]=1;
        v.push_back(i);
        for(auto j:adj[i])
        {
            if(!visited[j])
            {
                dfs(j,visited,adj,v);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int>visited(n,0);
        vector<int>v;
        dfs(0,visited,adj,v);
        return v;
    }
};
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} 

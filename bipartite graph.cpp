#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool check(int i,int col,vector<int>&color,vector<int>adj[])
{
    color[i]=col;
    for(auto j:adj[i])
    {
        if(color[j]==0)
        {
            if(!check(j,3-col,color,adj))
            return 0;
        }
            else if(color[i]==color[j])
            return 0;

    }
    return 1;
}
	bool isBipartite(int n, vector<int>adj[]){
	    vector<int>color(n,0);
	    for(int i=0;i<n;i++)
	    {
	        if(color[i]==0)
	        {
	            if(!check(i,1,color,adj))
	            return 0;
	        }
	    }
	    return 1;
	}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if(ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

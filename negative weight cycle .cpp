#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>adj){
	    int inf=1e8;
	    vector<int>dist(n,inf);
	    for(int i=0;i<n;i++)
	    {
	        for(auto j:adj)
	        {
	            int u=j[0],v=j[1],w=j[2];
	            dist[v]=min(dist[v],w+dist[u]);
	        }
	    }
	    for(auto j:adj)
	    {
	        int u=j[0],v=j[1],w=j[2];
	           if(dist[v]>w+dist[u])
	           return 1;
	    }
	    return 0;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;




class Solution
{
	public:

    void make_parent(int i,vector<int>&parent,vector<int>&rank)
    {
        parent[i]=i;
        rank[i]=0;
    }
    int find_set(int i,vector<int>&parent)
    {
        if(parent[i]==i)
        return i;
        return parent[i]=find_set(parent[i],parent);
    }
    void union_set(int a,int b,vector<int>&parent,vector<int>&rank)
    {
        a=find_set(a,parent);
        b=find_set(b,parent);
        if(a!=b)
        {
            if(rank[a]<rank[b])
            swap(a,b);
            parent[b]=a;
            rank[a]+=rank[b];
        }
    }
    int spanningTree(int n, vector<vector<int>> adj[])
    {
      vector<int>parent(n),rank(n,-1);
      vector<vector<int>>res;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<adj[i].size();j++)
          {
              vector<int>x=adj[i][j];
              vector<int>temp;
              temp.push_back(x[1]);
              temp.push_back(min(i,x[0]));
              temp.push_back(max(i,x[0]));
              res.push_back(temp);
              temp.clear();
          }
      }
      sort(res.begin(),res.end());
      for(int i=0;i<n;i++)
      {
          make_parent(i,parent,rank);
      }
      int cost=0;
      for(auto i:res)
      {
          int w=i[0],u=i[1],v=i[2];
          int x=find_set(u,parent);
          int y=find_set(v,parent);
          if(x==y)
          continue;
          else
          cost+=w;
          union_set(x,y,parent,rank);
      }
      return cost;
    }
};




int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

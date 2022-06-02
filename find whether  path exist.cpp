#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:

 bool dfs(int i,int j,int n,int m,vector<vector<int>>&visited,vector<vector<int>>& a)
 {
     if(i<0||i>=n||j<0||j>=m||a[i][j]==0||visited[i][j])
     return false;
     if(a[i][j]==2)
     return true;
     visited[i][j]=1;
     if(dfs(i+1,j,n,m,visited,a)||dfs(i,j+1,n,m,visited,a)||
     dfs(i-1,j,n,m,visited,a)||dfs(i,j-1,n,m,visited,a))
     return true;
     visited[i][j]=0;
     return false;
 }
    bool is_Possible(vector<vector<int>>& a)
    {
       int n=a.size(),m=a[0].size();
       int x,y;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(a[i][j]==1)
               {
                   x=i,y=j;
               }
           }
       }
       vector<vector<int>>visited(n,vector<int>(m,0));
       return dfs(x,y,n,m,visited,a);
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
} 

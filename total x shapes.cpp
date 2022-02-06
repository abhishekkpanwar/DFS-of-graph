#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:

    void dfs(int i,int j,int n,int m,vector<vector<int>>&visited,vector<vector<char>>&a)
    {
        if(i<0||j<0||i>=n|j>=m||a[i][j]=='O')
        return ;
        if(visited[i][j]!=1)
        {
            visited[i][j]=1;
            dfs(i+1,j,n,m,visited,a);
             dfs(i,j+1,n,m,visited,a);
              dfs(i-1,j,n,m,visited,a);
               dfs(i,j-1,n,m,visited,a);

        }
    }
    int xShape(vector<vector<char>>& a)
    {
       int n=a.size();
       int m=a[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j]&&a[i][j]=='X')
                {
                    dfs(i,j,n,m,visited,a);
                    count++;
                }
            }
        }
        return count;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
} 

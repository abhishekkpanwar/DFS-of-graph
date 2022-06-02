#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:

    void dfs(int i,int j,int n,int m,vector<vector<int>>&a,int &count)
    {
        if(i<0||i>=n||j<0||j>=m||a[i][j]==0)
        return ;
        count++;
        a[i][j]=0;
        dfs(i+1,j,n,m,a,count);
         dfs(i,j+1,n,m,a,count);
          dfs(i-1,j,n,m,a,count);
           dfs(i,j-1,n,m,a,count);
            dfs(i+1,j+1,n,m,a,count);
             dfs(i+1,j-1,n,m,a,count);
              dfs(i-1,j+1,n,m,a,count);
               dfs(i-1,j-1,n,m,a,count);
    }
    int findMaxArea(vector<vector<int>>& a) {
        int maxi=0;
        int n=a.size(),m=a[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,n,m,a,count);
                    maxi=max(maxi,count);
                }
            }
        }
        return maxi;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
} 

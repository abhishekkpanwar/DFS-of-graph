#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:

	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int n)
	{
	    int x1=kp[0],y1=kp[1],x2=tp[0],y2=tp[1];
	    if(x1==x2&&y1==y2)
	    return 0;
       int a[1001][1001];
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               a[i][j]=0;
           }
       }
       queue<pair<int,int>>q;
       q.push({x1-1,y1-1});
       while(!q.empty())
       {
           int i=q.front().first;
           int j=q.front().second;
           q.pop();
           if((i+1)>=0&&(i+1)<n&&(j+2)>=0&&(j+2)<n&&a[i+1][j+2]==0)
	       {
	           a[i+1][j+2]=a[i][j]+1;
	           q.push({i+1,j+2});
	       }
	       if((i-1)>=0&&(i-1)<n&&(j+2)>=0&&(j+2)<n&& a[i-1][j+2]==0)
	       {
	          a[i-1][j+2]=a[i][j]+1;
	          q.push({i-1,j+2});
	       }
	        if((i-2)>=0&&(i-2)<n&&(j+1)>=0&&(j+1)<n&&a[i-2][j+1]==0)
	       {
	           a[i-2][j+1]=a[i][j]+1;
	           q.push({i-2,j+1});
	       }
	       if((i+2)>=0&&(i+2)<n&&(j+1)>=0&&(j+1)<n&&a[i+2][j+1]==0)
	       {
	           a[i+2][j+1]=a[i][j]+1;
	           q.push({i+2,j+1});
	       }
	       if((i-1)>=0&&(i-1)<n&&(j-2)>=0&&(j-2)<n&&  a[i-1][j-2]==0)
	       {
	           a[i-1][j-2]=a[i][j]+1;
	           q.push({i-1,j-2});
	       }
	       if((i+1)>=0&&(i+1)<n&&(j-2)>=0&&(j-2)<n&&a[i+1][j-2]==0)
	       {
	          a[i+1][j-2]=a[i][j]+1;
	          q.push({i+1,j-2});
	       }
	       if((i-2)>=0&&(i-2)<n&&(j-1)>=0&&(j-1)<n&& a[i-2][j-1]==0)
	       {
	          a[i-2][j-1]=a[i][j]+1;
	          q.push({i-2,j-1});
	       }
	        if((i+2)>=0&&(i+2)<n&&(j-1)>=0&&(j-1)<n&&a[i+2][j-1]==0)
	       {
	           a[i+2][j-1]=a[i][j]+1;
	           q.push({i+2,j-1});
	       }
       }
       return a[x2-1][y2-1];
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  

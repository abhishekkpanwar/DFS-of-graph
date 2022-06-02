#include <bits/stdc++.h>
using namespace std;
    void topo(int i,vector<int>&visited,string &temp,vector<int>adj[])
    {
        visited[i]=1;
        for(auto j:adj[i])
        {
            if(!visited[j])
            {
                topo(j,visited,temp,adj);
            }
        }
        char c=i+'a';
        temp=c+temp;
    }
    string findOrder(string dict[], int n, int k) {
        vector<int>visited(k,0);
        string temp="";
        vector<int>adj[k+1];
        for(int i=0;i<n-1;i++)
        {
            string p=dict[i],q=dict[i+1];
            for(int j=0;j<min(p.length(),q.length());j++)
            {
                if(p[j]!=q[j])
                {
                    adj[p[j]-'a'].push_back(q[j]-'a');
                    break;
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            if(!visited[i])
            topo(i,visited,temp,adj);
        }
        return temp;
    }
int main()
{
    int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        cout<<findOrder(dict,N,K)<<endl;
        return 0;
}

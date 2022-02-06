#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> a){
       int k,p;
       for(k=n-2;k>=0;k--)
       {
           if(a[k]<a[k+1])
           break;
       }
       if(k<0)
       {
           reverse(a.begin(),a.end());
       }
       else
       {
           for(p=n-1;p>k;p--)
           {
               if(a[p]>a[k])
               break;
           }
           swap(a[p],a[k]);
           reverse(a.begin()+k+1,a.end());
       }
       return a;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
} 

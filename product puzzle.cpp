#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:

    vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
       vector<long long>p(n),q(n);
       p[0]=1,q[n-1]=1;
       for(int i=1;i<n;i++)
       {
           p[i]=p[i-1]*a[i-1];
       }
       for(int i=n-2;i>=0;i--)
       {
           q[i]=q[i+1]*a[i+1];
       }
       for(int i=0;i<n;i++)
       {
           a[i]=p[i]*q[i];
       }
       return a;
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long int> arr(n),vec(n);

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);

        for(int i=0;i<n;i++)
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  

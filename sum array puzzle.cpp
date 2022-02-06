#include <bits/stdc++.h>
using namespace std;

void SumArray(int[], int);
void SumArray(int a[], int n)
{
     vector<int>p(n),q(n);
       p[0]=0,q[n-1]=0;
       for(int i=1;i<n;i++)
       {
           p[i]=p[i-1]+a[i-1];
       }
       for(int i=n-2;i>=0;i--)
       {
           q[i]=q[i+1]+a[i+1];
       }
       for(int i=0;i<n;i++)
       {
           a[i]=p[i]+q[i];
       }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i = 0; i < n; i++)
          cin>>arr[i];

         SumArray(arr, n);
         for(int i = 0; i < n; i++)
            cout << arr[i] <<" ";


        cout <<endl;
    }
    return 0;
}

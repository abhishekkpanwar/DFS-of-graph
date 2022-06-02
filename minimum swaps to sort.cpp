#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&a)
	{
	    int count=0;
	    map<int,int>mp;
	    vector<int>p=a;
	    for(int i=0;i<a.size();i++)
	    {
	        mp[a[i]]=i;
	    }
	    sort(p.begin(),p.end());
	    for(int i=0;i<a.size();i++)
	    {
	        if(p[i]!=a[i])
	        {
	            count++;
	            swap(a[i],a[mp[p[i]]]);
	            swap(mp[a[i]],mp[a[mp[p[i]]]]);
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}

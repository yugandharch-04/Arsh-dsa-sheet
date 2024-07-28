//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<int> copy=nums;
	    sort(copy.begin(),copy.end());
	    int n=nums.size();
	    unordered_map<int,int> mp;
	    
	    for(int i=0;i<n;i++){
	        mp[nums[i]]=i;
	    }
	    
	    int ans=0;
	    
	    for(int i=0;i<n;i++){
	        if(copy[i]==nums[i]) continue;
	        mp[nums[i]]=mp[copy[i]];
	        swap(nums[i],nums[mp[copy[i]]]);
	        mp[nums[i]]=i;
	        ans++;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
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
// } Driver Code EndsR
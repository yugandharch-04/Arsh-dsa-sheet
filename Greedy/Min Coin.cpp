//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int id,vector<int> &nums,int su,vector<vector<int>> &dp)
	{
	    if(su<0) return 1e9;
	    if(su==0) return 0;
	    if(id==0){
	        if(su%nums[id]==0) return su/nums[id];
	        else return 1e9;
	    }
	    if(dp[id][su]!=-1) return dp[id][su];
	    if(nums[id]<=su) return dp[id][su] = min(1+solve(id,nums,su-nums[id],dp),solve(id-1,nums,su,dp));
	    else return dp[id][su] = solve(id-1,nums,su,dp);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n = nums.size();
	    sort(nums.begin(),nums.end());
	    vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
	    int fun = solve(n-1,nums,amount,dp);
	    if(fun==1e9) return -1;
	    else return fun;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
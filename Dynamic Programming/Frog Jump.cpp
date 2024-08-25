class Solution {
public:
bool solve(int ind,int k,vector<int>& nums,vector<vector<int>>& dp){
    int n=nums.size();
    if(ind==n-1) return dp[ind][k]=true;
    if(ind>=n) return false;
    if(dp[ind][k]!=-1) return dp[ind][k];
    int temp=0;
    for(int j=ind+1;j<n;j++){
        temp=nums[j]-nums[ind];
        if(temp>=k-1 && temp<=k+1){
            if(solve(j,temp,nums,dp)) return dp[ind][k]=true;
        }
       
    }
    return dp[ind][k]=false;
}
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;
        int n=stones.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,1,stones,dp);
    }
};
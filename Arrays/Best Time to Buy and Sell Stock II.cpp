class Solution {
public:
    int solve(vector<int> &prices,int ind,int buy,vector<vector<int>> &dp){
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            dp[ind][buy]=max(solve(prices,ind+1,0,dp)-prices[ind],solve(prices,ind+1,1,dp));
        }
        else{
            dp[ind][buy]=max(solve(prices,ind+1,1,dp)+prices[ind],solve(prices,ind+1,0,dp));
        }
        return dp[ind][buy];

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};
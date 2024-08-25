class Solution {
public:
    int solve(vector<int> &prices,int ind,int buy,int chance,vector<vector<vector<int>>> &dp){
        if(ind==prices.size()) return 0;
        if(chance<=0) return 0;
        if(dp[ind][buy][chance]!=-1) return dp[ind][buy][chance];
        if(buy){
            dp[ind][buy][chance]=max(solve(prices,ind+1,0,chance,dp)-prices[ind],solve(prices,ind+1,1,chance,dp));
        }
        else{
            dp[ind][buy][chance]=max(solve(prices,ind+1,1,chance-1,dp)+prices[ind],solve(prices,ind+1,0,chance,dp));
        }
        return dp[ind][buy][chance];

    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,k,dp);
    }
};
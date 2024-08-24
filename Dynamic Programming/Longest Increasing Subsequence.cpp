class Solution {
public:
// recursion 
    int solve(vector<int> & nums, int ind,int prevind,vector<vector<int>> &dp){
        if(ind>=nums.size()) return 0;
        if(dp[ind][prevind]!=-1) return dp[ind][prevind];
        if(prevind==0){
            return dp[ind][prevind]=max(1+solve(nums,ind+1,ind+1,dp),solve(nums,ind+1,prevind,dp));
        }
        if(nums[ind]>nums[prevind-1]){
            return dp[ind][prevind]=max(1+solve(nums,ind+1,ind+1,dp),solve(nums,ind+1,prevind,dp));

        }
        return dp[ind][prevind]=solve(nums,ind+1,prevind,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+2,0));
        // return solve(nums,0,0,dp);
        //tabulation ----------------------------------------------------------------------
        // for(int ind=nums.size()-1;ind>=0;ind--){
        //     for(int prevind=nums.size()-1;prevind>=0;prevind--){
        //         if(prevind==0){
        //             dp[ind][prevind]=max(1+dp[ind+1][ind+1],dp[ind+1][prevind]);
        //         }
        //         else if(nums[ind]>nums[prevind-1]){
        //             dp[ind][prevind]=max(1+dp[ind+1][ind+1],dp[ind+1][prevind]);

        //         }
        //         else dp[ind][prevind]=dp[ind+1][prevind];
        //     }
        // }
        // return dp[0][0];
        //------------------------------------------------------------------------------------

        //algo --------------------------------------------------------------------------------
        // vector<int> dp2(n,1);
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]) dp2[i]=max(dp2[i],1+dp2[j]);
        //     }
        //     ans=max(ans,dp2[i]);

        // }
        // return ans;
        //------------------------------------------------------------------------------------

        //binary search---------------------------------------------------------------------------
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }

        return temp.size();
    }
};
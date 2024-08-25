class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
       
        vector<int> arr(10001,0);
        for(auto it : nums){
            arr[it]++;
        }
        int n=arr.size();
        vector<int> dp(n+2,0);
        // dp[n-1]=arr[n-1].first*arr[n-1].second;
        for(int i=n-1;i>=0;i--){
            int val=i*arr[i];
            dp[i]=max(dp[i+1],val+dp[i+2]);
        }
        
        return dp[0];
    }
};
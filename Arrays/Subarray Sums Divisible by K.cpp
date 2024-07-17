class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(auto num: nums){
            sum=(sum+num)%k;
            if(sum<0) sum+=k;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
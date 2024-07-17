class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,count=0;
        unordered_map<int,int> m;
        m[0]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};
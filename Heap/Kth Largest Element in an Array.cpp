class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int,greater<int>> mse(nums.begin(),nums.end());
        auto itr=mse.begin();
        advance(itr,k-1);
        return *itr;
    }
};
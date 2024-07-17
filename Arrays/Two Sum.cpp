class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<pair<int,int>> nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back({arr[i],i});
        }
       sort(nums.begin(),nums.end());
       int s=0;
       int e=nums.size()-1;
       while(s<e){
            if(nums[s].first+nums[e].first==target) return {nums[s].second,nums[e].second};
            if(nums[s].first+nums[e].first > target) e--;
            else s++; 
       }
       return {-1,-1};
    }
};
class Solution {
public:
    vector<vector<int>> helper(vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,int index){
        if(index==nums.size()){
            ans.push_back(temp);
            return ans;
        }
        temp.push_back(nums[index]);
        ans=helper(nums,ans,temp,index+1);
        temp.pop_back();
        ans=helper(nums,ans,temp,index+1);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        return helper(nums,ans,temp,0);
    }
};
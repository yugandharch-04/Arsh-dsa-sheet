// Subsets II
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++)
                if (i & 1 << j)
                    temp.push_back(nums[j]);
            ans.insert(temp);
        }
        vector<vector<int>> final_ans(ans.begin(), ans.end());
        return final_ans;
    }
};

/* Following is the solution to Subset-1 problem, check the difference and how minutely the code is changed.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> temp;
            for (int j = 0; j < nums.size(); j++)
                if (i & 1 << j)
                    temp.push_back(nums[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};*/
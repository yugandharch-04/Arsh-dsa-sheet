class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a,b,c;int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<=n-3;i++){
            a=nums[i]*-1;
            if(i==0 || nums[i]!=nums[i-1]){
                int low=i+1;
                int high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]==a){
                        ans.push_back({a*-1,nums[low],nums[high]});
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++;high--;
                    }
                    while(low<high&&(nums[low]+nums[high]>a)) high--;
                    while(low<high&&(nums[low]+nums[high]<a)) low++;

                }
            }

        }
        return ans;
        
    }
};
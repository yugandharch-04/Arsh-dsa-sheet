class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int a,b,c,d;int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<=n-4;i++){
            if(i==0 || nums[i]!=nums[i-1])
            for(int j=i+1;j<=n-3;j++){
                long long sum=(target*1LL)-nums[i]-nums[j];
                if(j==i+1 || nums[j]!=nums[j-1]){
                    int low=j+1;
                    int high=n-1;
                    
                    while(low<high){
                        if(nums[low]+nums[high]==sum){
                            ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                            while(low<high && nums[low]==nums[low+1]) low++;
                            while(low<high && nums[high]==nums[high-1]) high--;
                            low++;high--;
                        }
                        while(low<high&&(nums[low]+nums[high]>sum)) high--;
                        while(low<high&&(nums[low]+nums[high]<sum)) low++;
                    }
                }
            }
        }
        return ans;
    }
};
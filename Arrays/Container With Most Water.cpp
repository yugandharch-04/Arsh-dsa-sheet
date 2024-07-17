class Solution {
public:
    int maxArea(vector<int>& nums) {
        int ans=0;int n=nums.size();
        //Brute forcce O(n^2);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         ans=max(ans,min(nums[i],nums[j])*(j-i));
        //     }
        // }
        // return ans;
        
        int start=0;int end=n-1;
        while(start<end){
            ans=max(ans,min(nums[start],nums[end])*(end-start));
            if(nums[start]<nums[end]) start++;
            else end--;
        }
        return ans;
    }
};
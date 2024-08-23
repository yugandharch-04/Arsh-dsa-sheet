class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pref=1;
        int suf=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            pref=pref*nums[i];
            suf=suf*nums[n-i-1];
            maxi=max(maxi,max(pref,suf));
            if(pref==0) pref=1;
            if(suf==0) suf=1;
        }
        return maxi;
    }
};
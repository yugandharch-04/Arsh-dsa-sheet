class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cj=nums[0];
        
        int n=nums.size();
        if(n==1) return true;
        if(cj==0) return false;
        for(int i=1;i<n-1;i++){
            cj--;
            if(cj<0) return false;
            if(cj<nums[i]) cj=nums[i];
            if(cj==0) return false;

        }
        return true;
    }
};
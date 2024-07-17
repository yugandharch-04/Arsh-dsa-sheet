class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replaceInd=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                replaceInd++;
                nums[replaceInd]=nums[i];
            }
        }
        return replaceInd+1;
    }
};
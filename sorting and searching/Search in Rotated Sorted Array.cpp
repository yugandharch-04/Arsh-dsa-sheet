class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int n=nums.size();
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return mid;
            //left side is sorted
            if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target<=nums[mid]){
                    h=mid-1;
                }
                else l=mid+1;
            }
            //right side sorted
            else{
                if(target>=nums[mid] && target<=nums[h]){
                    l=mid+1;

                }
                else h=mid-1;
            }

        }
        return -1;

    }
};
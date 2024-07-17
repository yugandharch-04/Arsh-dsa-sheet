class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int e;
        for(int n : nums){
            if(count==0) e=n;
            if(e==n) count++;
            else count--;
        }
        return e;
    }
};
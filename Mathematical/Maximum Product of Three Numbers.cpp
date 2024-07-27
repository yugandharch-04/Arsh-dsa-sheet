class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int ans=nums[n-3]*nums[n-2]*nums[n-1];
       int i=0;int j=n-3;
       int count=3;
        int temp=ans;
       while(count--){
        if(nums[j]!=0) temp/=nums[j];
        else{
            temp=1;
            for(int h=n-1;h>j;h--) temp*=nums[h];
            for(int h=0;h<i;h++) temp*=nums[h];
        }
        j++;
        temp*=nums[i];
        i++;
        ans=max(ans,temp);
       }
       return ans;

    }
};
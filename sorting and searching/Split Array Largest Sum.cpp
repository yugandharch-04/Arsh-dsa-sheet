class Solution {
public:
    bool comp(vector<int>& nums, int k,int mid){
        int sum=0;
        for(auto num : nums){
            sum+=num;
            if(sum>mid){
                k--;
                sum=num;
            }

        }
        k--;
        return k>=0;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) return -1;

        int l=INT_MIN;

        for(int i=0;i<n;i++){

            l=max(l,nums[i]);

        }

        if(k==n) return l;
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(comp(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
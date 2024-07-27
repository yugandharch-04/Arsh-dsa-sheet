//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool comp(int arr[], int n, int m,int mid){
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                m--;
                sum=arr[i];
            }
        }
        m--;
        return m>=0;
    }
    int findPages(int arr[], int n, int m) 
    {
        //code here
if(m>n) return -1;
        int l=INT_MIN;
        for(int i=0;i<n;i++){
            l=max(l,arr[i]);
        }
        if(m==n) return l;
        
        long long int h=1e9;
        long long int ans=-1;
        while(l<=h){
            long long int mid=l+(h-l)/2;
            if(comp(arr,n,m,mid)){
                ans=mid;h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
class Solution {
public:
    long long mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> lefty;
        vector<int> righty;
        stack<pair<int,int>> stl;
        stack<pair<int,int>> str;
        for(int i=0;i<arr.size();i++){
            if(stl.empty()){
                stl.push({arr[i],1});
                lefty.push_back(1);
            }
            else{
                int count=1;
                while(!stl.empty() && stl.top().first>=arr[i]){
                    count+=stl.top().second;
                    stl.pop();
                    
                }
                stl.push({arr[i],count});
                lefty.push_back(count);
            }
            if(str.empty()){
                str.push({arr[n-i-1],1});
                righty.push_back(1);
            }
            else{
                int count=1;
                while(!str.empty() && str.top().first>=arr[n-i-1]){
                    count+=str.top().second;
                    str.pop();
                    
                }
                str.push({arr[n-i-1],count});
                righty.push_back(count);
            }
        }
        reverse(righty.begin(),righty.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(((arr[i])%mod)*1LL*lefty[i]*1LL*righty[i])%mod;
        }
        return ans;
    }
};
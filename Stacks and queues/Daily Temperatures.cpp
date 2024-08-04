class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n=temp.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
                st.push(i);
                
            }
            else{
                
                while(!st.empty() && temp[st.top()]<=temp[i]){
                    st.pop();
                    
                }
                if(st.empty()){
                    ans[i]=0;
                    st.push(i);
                }
                else{
                    
                    ans[i]=st.top()-i;
                    st.push(i);
                }
                
                
            }
        }
        return ans;
    }
};
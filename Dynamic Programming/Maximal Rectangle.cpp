class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int ans=0;
        stack<int> st;
        
        for(int i=0;i<=n;i++){
            
            while(!st.empty() && (i==n || h[st.top()]>=h[i])){
                int height=h[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                ans=max(ans,height*width);
            }
            st.push(i);            
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        vector<int> temp(matrix[0].size(),0);
        for(auto r : matrix){
            for(int i=0;i<r.size();i++){
                if(r[i]=='1') temp[i]++;
                else temp[i]=0;
            }
            ans=max(ans,largestRectangleArea(temp));
        }
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char a: s){
            if(st.empty()){
                st.push({a,1});

            }
            else{
                if(st.top().first==a){
                    st.top().second++;
                    if(st.top().second==k) st.pop();
                }
                else{
                    st.push({a,1});
                }
            }
        }
        string ans;
        while(st.empty()==false){
            char a=st.top().first;
            int count=st.top().second;
            st.pop();
            while(count--) ans.push_back(a);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
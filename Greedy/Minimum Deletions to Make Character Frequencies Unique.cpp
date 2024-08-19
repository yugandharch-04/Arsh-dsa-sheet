class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);

        for(auto ch : s) v[ch-'a']++;
        set<int>st;
        int res = 0;
        sort(v.begin() , v.end() , greater<int>());
        // for(auto ele : v)cout<<ele<<" ";
        for(auto ele : v){
            if(ele ==0)continue;
            if(st.find(ele) == st.end()) st.insert(ele);
            else{
                while(st.find(ele) != st.end() ){
                    ele--;
                    res++;
                }
                if(ele != 0)st.insert(ele);
            }
        }
        return res;
    }
};
class Solution {
public:
    string common(string a,string b){
        int n=min(a.size(),b.size());
        string ans="";
        for(int i=0;i<n;i++){
            if(a[i]==b[i]) ans.push_back(a[i]);
            else break;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1) return strs[0];
        string com=common(strs[0],strs[1]);
        if(n==2) return com;
        for(int i=2;i<n;i++){
            com=common(com,strs[i]);
            if(com=="") return com;
        }
        return com;
    }
};
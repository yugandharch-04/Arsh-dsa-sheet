class Solution {
public:
    vector<string> helper(vector<string> &ans,string &temp,int opening,int pairs){
        if(opening<0 || pairs<0) return ans;
        if(opening > pairs) return ans;
        if(pairs==0){
            ans.push_back(temp);
            return ans;
        }
        temp.push_back('(');
        ans=helper(ans,temp,opening+1,pairs);
        temp.pop_back();
        temp.push_back(')');
        ans=helper(ans,temp,opening-1,pairs-1);
        temp.pop_back();
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        return helper(ans,temp,0,n);
    }
};
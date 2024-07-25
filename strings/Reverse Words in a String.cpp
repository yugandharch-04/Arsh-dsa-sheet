class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        stack<string> stk;
        for(auto ch : s){
            if(ch==' ' && temp.size()==0) continue;
            if(ch==' ' && temp.size()!=0) {stk.push(temp);temp="";}
            else temp.push_back(ch);
        }
        if(temp.size()!=0) stk.push(temp);
        string ans="";
        while(!stk.empty()){
            ans=ans+stk.top()+' ';
            stk.pop();
        }
        ans.pop_back();
        return ans;
        
    }
};
class Solution {
public:
    bool ispalindrome(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void helper(vector<vector<string>> & ans,vector<string> &temp,string & s,int start){
        
        if(start==s.size()){
            ans.push_back(temp);
            return ;
            
        }
        for(int j = start;j<s.size();j++){
            if(ispalindrome(s,start,j)){
                temp.push_back(s.substr(start,j-start+1));
                helper(ans,temp,s,j+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(ans,temp,s,0);return ans;
    }
};
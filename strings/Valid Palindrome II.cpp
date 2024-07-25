class Solution {
public:
    bool check(string &s,int i,int j,int free){
        if(i>=j) return true;
        if(s[i]==s[j]) return check(s,i+1,j-1,free);
        if(free==0) return false;
        if(check(s,i+1,j,0)) return true;
        if(check(s,i,j-1,0)) return true;
        return false;
    }
    bool validPalindrome(string s) {
        return check(s,0,s.size()-1,1);
    }
};
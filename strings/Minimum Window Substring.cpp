class Solution {
public:
    //my solu -----------------------------------------------------------

    // bool check(map<char,int> &a,map<char,int> & b){
    //     // if(a.size())
    //     for(auto it: a){
    //         if(b[it.first]<it.second) return false;
    //     }
    //     return true;
    // }
    // string minWindow(string s, string t) {
    //     int ans_i=0,ans_j=0,n=s.size(),m=t.size(),minlen=INT_MAX;
    //     if(m>n) return "";
    //     map<char,int> a;
    //     map<char,int> b;
    //     for(auto it : t) a[it]++;

    //     int i=0,r=0;
    //     while(r<n){
    //         b[s[r]]++;
    //         while(check(a,b)){
    //             b[s[i]]--;
    //             if(b[s[i]]==0) b.erase(s[i]);
    //             if(minlen>r-i+1){
    //                 ans_i=i;ans_j=r;minlen=r-i+1;
    //             }
    //             i++;
    //         }
    //         r++;
    //     }
    //     if(minlen==INT_MAX) return "";
    //     return s.substr(ans_i,minlen);
    // }
    //--------------------------------------------------------------

    string minWindow(string s, string t) {
        vector<int>map(126,0);
        for(auto i : t)map[i]++;

        int startindex=0;
        int end=0;
        int begin=0;

        int minLen=INT_MAX; 
        int count=t.size();

        while(end < s.size()){
            if(map[s[end++]]-- > 0){
                count--;
            }
            while(count==0){
                if(minLen > end-begin){
                    minLen=end-begin;
                    startindex=begin;
                }
                if(map[s[begin++]]++ == 0){
                    count++;
                }
            }
        }
        return minLen==INT_MAX ? "":s.substr(startindex,minLen);

    }

};
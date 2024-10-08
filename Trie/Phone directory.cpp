//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
    const int m = s.size();
        vector<vector<string>> ans(m, vector<string>());
        sort(contact, contact + n);
        
        for(int i=0; i<n; ++i) {
            string word = contact[i];
            if(i > 0 and word == contact[i-1])
                continue;
            int j=0;
            while(j < m and j < word.size() and s[j] == word[j]) 
                ans[j++].push_back(word);
        }
        for(int j=0; j<m; ++j) {
            if(ans[j].empty())
                ans[j].push_back("0");
        }
        return ans; }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
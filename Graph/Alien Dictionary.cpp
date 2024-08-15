//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    void topo(vector<int>adj[], stack<int>&st, vector<int>&vis, int src){
        vis[src] = 1;
        
        for(auto it: adj[src]){
            if(!vis[it]){
                topo(adj, st, vis, it);
            }
        }
        
        st.push(src);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        vector<int>vis(K, 0);
        string ans;
        
        for(int i=0;i<N-1;i++){
            int j=0;
            int n = dict[i].size();
            int m = dict[i+1].size();
            
            int len = min(n, m);
            
            while(j<len && dict[i][j] == dict[i+1][j])
                j++;
            
            if(j!=len){
                adj[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
            }
        }
        
        stack<int>st;
        for(int i=0;i<K;i++){
            if(!vis[i])
                topo(adj, st, vis, i);
        }
        
        while(!st.empty()){
            int f = st.top();
            st.pop();
            char ch = f + 'a';
            ans = ans + ch;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    void dfs(vector<vector<int>> &arr, int n, int left, int right,
    string s, vector<string> &ans, vector<vector<int>> &visited){
        if(left>=n || right>=n || left<0 || right<0 || arr[left][right] == 0 || visited[left][right] == 1){
            return ;
        }
        if(left == n-1 && right == n-1){
            ans.push_back(s);
            return ;
        }
        
        visited[left][right] = 1;
        
        dfs(arr,n,left-1,right,s+"U",ans,visited);
        dfs(arr,n,left+1,right,s+"D",ans,visited);
        dfs(arr,n,left,right-1,s+"L",ans,visited);
        dfs(arr,n,left,right+1,s+"R",ans,visited);
        
        visited[left][right] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &arr) {
        // Your code goes here
        int n =arr.size();
        string s = "";
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n,0));
        
        if(arr[0][0] == 1){
            dfs(arr,n,0,0,"",ans,visited);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
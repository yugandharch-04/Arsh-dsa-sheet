//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<int>>& vis, vector<vector<char>> & grid ,int i,int j){
        int n=grid.size();int m=grid[0].size();
        auto check=[&](int i,int j)->bool{
            return i<n && j<m && i>=0 && j>=0;
        };
        vis[i][j]=1;
        
        for(int di=-1;di<2;di++){
            for(int dj=-1;dj<2;dj++){
                if(check(i+di,j+dj) && grid[i+di][j+dj]=='1' && vis[i+di][j+dj]==-1){
                    dfs(vis,grid,i+di,j+dj);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    dfs(vis,grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
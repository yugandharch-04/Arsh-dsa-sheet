class Solution {
public:
    int path(int m, int n, int i ,int j,vector<vector<int>>&dp)
{
    if(i==m-1 && j==n-1)return 1;
    if(i>=m || j>=n)return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    int down=path(m,n,i+1,j,dp);
    int right=path(m,n,i,j+1,dp);
    dp[i][j]=down+right;
    return dp[i][j];

}
    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m,n,0,0,dp);
    }
};
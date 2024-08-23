class Solution {
public:
    int ans=INT_MAX;
        int path(int m, int n, int i ,int j,vector<vector<int>>&dp,int sum,vector<vector<int>>& grid)
{
    if(i>=m || j>=n)return 1e8;
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(i==m-1 && j==n-1){
       return dp[i][j]=grid[i][j];
        
    }
    
    
    int down=grid[i][j]+path(m,n,i+1,j,dp,sum,grid);
   int right= grid[i][j]+path(m,n,i,j+1,dp,sum,grid);
    return dp[i][j]=min(down,right);

}
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
         int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(m,n,0,0,dp,0,grid);
       
    }
};
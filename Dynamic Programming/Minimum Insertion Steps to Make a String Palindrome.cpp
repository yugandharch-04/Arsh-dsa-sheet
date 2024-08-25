class Solution {
public:
int solve(string& s,int i,int j,vector<vector<int>> & dp){
	if(i>=j){
		// if(temp.size()>ans.size()) ans=temp;
		return 0;
	}
	if(dp[i][j]!=0) return dp[i][j];
	if(s[i]==s[j]) {
		dp[i][j]=solve(s,i+1,j-1,dp);
		// temp.push_back(s[i]);
		// solve(s,str,i+1,j+1,temp);
		// temp.pop_back();
		
	}
	else{
		dp[i][j]=1+min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
		// solve(s,str,i+1,j,temp);
		// solve(s,str,i,j+1,temp);
	}
	return dp[i][j];

}
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return solve(s,0,n-1,dp);
    }
};
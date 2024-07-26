class Solution {
public:
    int numDistinct(string s1, string s2) {
         int n=s1.size();int m=s2.size();
        vector<vector<double>> dp(n+2,vector<double>(m+2,0));
        for(int i=0;i<=n+1;i++)  dp[i][m]=1;
	 for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j]) {
                    dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
            }
        }
        return (int)dp[0][0];
    }
};
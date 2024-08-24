class Solution {
public:
    int dp[1021][1002];
    int rec(int i , int j ) {
        if (i >= a.size() or j >= b.size() ) return  0 ;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (a[i] == b[j])
            ans  =   1 + rec(i + 1, j + 1);
        else ans  = 0 ;
        return dp[i][j] = ans ;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        int ans = 0 ;
        for (int i = 1 ; i <= a.size() ; i++) {
            for (int j = 1 ; j <= b.size() ; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans  ;

    }
};
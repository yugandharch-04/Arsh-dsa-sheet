class Solution {
public:
    int t[46];

    int climbStairs(int n) {
        if(n<=2) return n;
        if(t[n]!=0) return t[n];
        return t[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
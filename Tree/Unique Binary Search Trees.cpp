class Solution {

    using ll = long long;

    // Function To Calculate nCr : 
    ll nCr (int n, int r)
    {
        r = min(r,n-r);

        ll Ans = 1;
        for(int i=1;i<=r;i++)
            Ans = Ans * (n-r+i) / i ;
        
        return Ans;
    }

public:

    int numTrees(int n) {
        return int(nCr(2*n, n) / (n+1))  ;
    }

};
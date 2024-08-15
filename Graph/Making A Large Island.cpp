class disjointset{
    public:
    vector<int>par, sz;
    disjointset(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=0; i<n; i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int findp(int u){
        if(u==par[u]){
            return u;
        }
        return par[u]=findp(par[u]);
    }
    void un(int u, int v){
        int pu=findp(u), pv=findp(v);
        if(pu==pv){return;}
        if(sz[pu]<sz[pv]){
            par[pu]=pv;
            sz[pv]+=sz[pu];
        }
        else{
            par[pv]=pu;
            sz[pu]+=sz[pv];
        }
    }
};
class Solution {
public:
    bool chk(int i, int j, int n){return i>=0 && i<n && j>=0 && j<n;}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(), cnt=0;
        disjointset d(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int r[4]={-1, 0, 1, 0};
                    int c[4]={0, -1, 0, 1};
                    for(int k=0; k<4; k++){
                        int row=r[k]+i, col=c[k]+j;
                        if(chk(row, col, n) && grid[row][col]==1){
                            d.un(i*n+j, row*n+col);
                        }
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    set<int>s;
                    int r[4]={-1, 0, 1, 0};
                    int c[4]={0, -1, 0, 1};
                    for(int k=0; k<4; k++){
                        int row=r[k]+i, col=c[k]+j;
                        if(chk(row, col, n) && grid[row][col]==1){
                            s.insert(d.findp(row*n+col));
                        }
                    }
                    int ans=0;
                    for(auto it: s){
                        ans+=d.sz[d.findp(it)];
                    }
                    cnt=max(cnt, ans+1);
                }
            }
        }
        for(int i=0; i<n*n; i++){
            cnt=max(cnt, d.sz[d.findp(i)]);
        }
        return cnt;
    }
};
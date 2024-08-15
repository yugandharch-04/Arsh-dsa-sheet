class Solution {
public:
    bool check_cor(int i,int j,int n, int m){
        return ( i>=0 && j>=0 && i<n && j<m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        //bfs
        if(grid[sr][sc]==color) return grid;
        queue<pair<int,int>> que;
        int n=grid.size(),m=grid[0].size();
        que.push({sr,sc});
        int str_col=grid[sr][sc];
        grid[sr][sc]=color;
        int d_x[]={1,-1,0,0};
        int d_y[]={0,0,1,-1};
        while(!que.empty()){
            int r_i=que.front().first;
            int r_j=que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
               
                if(check_cor(r_i+d_x[i],r_j+d_y[i],n,m) && grid[r_i+d_x[i]][r_j+d_y[i]]==str_col){
                    grid[r_i+d_x[i]][r_j+d_y[i]]=color;
                    que.push({r_i+d_x[i],r_j+d_y[i]});
                }
                
            }
            
        }
        
        
        return grid;
    }
};
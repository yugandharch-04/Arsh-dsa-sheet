// N-Queens
class Solution {
public:
    bool isok(int row,int col,vector<string> &board,int n){
        if(col==0) return true;
        int rc=row;
        int cc=col;
        while(cc>=0){
            if(board[row][cc]=='Q'){
                return false;
            }
            cc--;
        }
        cc=col;
        while(rc>=0 && cc>=0){
            if(board[rc][cc]=='Q'){
                return false;
            }
            rc--;cc--;
        }
        rc=row;
        cc=col;
        while(rc<n && cc>=0){
            if(board[rc][cc]=='Q'){
                return false;
            }
            rc++;cc--;
        }
        return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            if(isok(i,col,board,n)){
                board[i][col]='Q';
                solve(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
            
        }
        solve(0,board,ans,n);
        return ans;
        
    }
};
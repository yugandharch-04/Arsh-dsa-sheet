class Solution {
public:
    bool helper(vector<vector<char>>&board,string &word,int ind,int i,int j){
        if(ind>=word.size()) return true;
        if(board[i][j]!=word[ind]) return false;
        bool ans=false;
        board[i][j]='.';
        int m=board.size();
        int n=board[0].size();
        
       if(i+1<m )
           ans=ans||helper(board,word,ind+1,i+1,j);
        if(j-1>=0)
            ans=ans||helper(board,word,ind+1,i,j-1);
        if(i-1>=0)
            ans=ans||helper(board,word,ind+1,i-1,j);
        if(j+1<n)
            ans=ans||helper(board,word,ind+1,i,j+1);
        board[i][j]=word[ind];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==1 and board[0][0]==word[0]) return true;
        bool ans=false;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j])
                { board[i][j]='.';
                     if(i+1<m )
                         ans=ans||helper(board,word,1,i+1,j);
                    if(j-1>=0)
                        ans=ans||helper(board,word,1,i,j-1);
                    if(i-1>=0)
                        ans=ans||helper(board,word,1,i-1,j);
                    if(j+1<n)
                        ans=ans||helper(board,word,1,i,j+1);
                 board[i][j]=word[0];
                 }
            }
        }
        return ans;
    }
};
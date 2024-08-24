class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int sum=0;
        vector<vector<int>> matrix(a.size(),vector<int>(a[0].size(),0));
        for(int i=0;i<a.size();i++){
            
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]=='1') matrix[i][j]=1;
            }
        }
        for(int i=1;i<matrix.size();i++){
            
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]) matrix[i][j]=1+min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]));
                
            }
        }
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                sum=max(sum,matrix[i][j]);
            }
        }
        return sum*sum;
    }
};
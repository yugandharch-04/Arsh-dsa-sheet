class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int sum=0;
        for(int i=1;i<matrix.size();i++){
            
            for(int j=1;j<matrix[i].size();j++){
                if(matrix[i][j]) matrix[i][j]=1+min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]));
                
            }
        }
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
};
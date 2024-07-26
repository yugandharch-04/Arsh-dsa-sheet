class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int startCol=0,endCol=m-1;
        int startRow=0,endRow=n-1;
        vector<int> ans;
        while(ans.size()<m*n){
            for(int i=startCol;ans.size()<m*n && i<=endCol;i++){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            for(int i=startRow;ans.size()<m*n && i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            for(int i=endCol;ans.size()<m*n && i>=startCol;i--){
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;
            for(int i=endRow;ans.size()<m*n && i>=startRow;i--){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        return ans;
    }
};
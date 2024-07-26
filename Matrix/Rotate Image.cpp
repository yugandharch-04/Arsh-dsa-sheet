class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int s=0;int e=n-1;
        while(s<e){
            swap(matrix[s],matrix[e]);
            s++;e--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
    }
};
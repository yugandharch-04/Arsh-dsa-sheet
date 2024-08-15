class Solution {
public:
    void shortest_distance(vector<vector<int>>&matrix) {
		int n = matrix.size();
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}

	}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto it : edges){
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        shortest_distance(mat);
        int ans=-1;
        int mincount=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mincount){
                mincount=count;
                ans=i;
            }
        }
        return ans;
    }
};
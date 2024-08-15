//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	     int rows = matrix.size();
        int columns = matrix[0].size();
  
       for( int k =0; k<rows; k++)
       {
           for(int i =0; i<rows; i++)
           {
               for(int j =0; j<columns; j++)
               {
                   int x = matrix[i][k];
                   int y = matrix[k][j];
                   if(x!=-1 && y!=-1)
                   {
                      if(matrix[i][j] == -1 || x+y <matrix[i][j])
                      matrix[i][j] = x+y; 
                   }
                   
               }
           }
       }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
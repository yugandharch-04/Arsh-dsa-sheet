//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        //multisource bfs
        queue<pair<int,int>> list;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==2) 
        list.push({i,j});
        int dx[]={-1,+1,0,0};
        int dy[]={0,0,-1,1};
        int ans=0;
        int count=list.size();
        while(list.empty()==false){
            auto start=list.front();
            int i=start.first;
            int j=start.second;
            list.pop();
            count--;
            for(int a=0;a<4;a+=1){
               int ix=dx[a];
               int jx=dy[a];
                    if(i+ix<n && i+ix>=0 && j+jx<m && j+jx>=0 && grid[i+ix][j+jx]==1){
                        grid[i+ix][j+jx]=2;
                        list.push({i+ix,j+jx});
                    }
                
            }
            if(count==0){
                count=list.size();
                ans++;
            }
            
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==1) 
        return -1;
        return ans==0? 0:ans-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
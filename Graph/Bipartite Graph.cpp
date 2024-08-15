//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	 bool IsBiP(int Node,vector<int>adj[],vector<int>&color)
    {
        for(int j=0;j<adj[Node].size();j++)
        {
            if(color[adj[Node][j]]==-1)
            {
                color[adj[Node][j]]=(color[Node]+1)%2;
                if(!IsBiP(adj[Node][j],adj,color))
                return 0;
            }
            else{
                if(color[Node]==color[adj[Node][j]])
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V,-1);
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(!IsBiP(i,adj,color))
                return 0;
            }
        }
        return 1;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<bool>& vis,vector<bool> &pathvis,vector<int> adj[],int v){
        vis[node]=1;
        pathvis[node]=1;
        for(auto child: adj[node]){
            if(vis[child]==false){
                if(dfs(child,vis,pathvis,adj,v)) return true;
            }
            else if(pathvis[child]) return true;
        }
        pathvis[node]=0;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<bool> vis(v,false),pathvis(v,false);
        
        for(int i=0;i<v;i++){
            if(vis[i]==false){
                if(dfs(i,vis,pathvis,adj,v)) return true;
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
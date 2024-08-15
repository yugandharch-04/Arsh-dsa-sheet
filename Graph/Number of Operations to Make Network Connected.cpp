class Solution {
public:
 
   void dfs(unordered_map<int,vector<int>> &adj,vector<bool> &visited,int u){
       if(visited[u]==true) return;

       visited[u]=true;
       for(auto &v : adj[u]){
           if(visited[v]==false){
              dfs(adj,visited,v);
           }
       }
   }


    int makeConnected(int n, vector<vector<int>>& box) {
        int cable_connection = box.size();
        if(cable_connection<n-1){
            return -1;
        }
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<box.size();i++){
            int u = box[i][0];
            int v = box[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
   
       int cnt = 0;
       vector<bool> visited(n,false);
       for(int i=0;i<n;i++){
                if(visited[i]==false){
                    cnt++;
                    dfs(adj,visited,i);
                }
       }
       return cnt-1;
    }
};
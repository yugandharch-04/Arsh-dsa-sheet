class Solution {
public:
    bool dfs(int v,vector<vector<int>> adj,int node, vector<int>& vis,vector<int> & path,vector<int> & check){
        vis[node]=1;
        path[node]=1;
        check[node]=0;
        for(auto child: adj[node]){
            if(!vis[child]){
                if(dfs(v,adj,child,vis,path,check)) return true;
            }
            else if(path[child]) return true;
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> check(n,0);
        //dfs----> giving TLE

        // vector<int> vis(n,0),path(n,0);
        // for(int i=0;i<n;i++){
        //     if(!vis[i]) {
        //         dfs(n,graph,i,vis,path,check);
        //     }
        // }
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(check[i]) ans.push_back(i);
        // }
        // return ans;

        //bfs kahn's algo
        // the topo answerr vector stores the vertices which are not a part of a cycle and which do not go into a path of a cycle

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);

            }
        }
        vector<int> ans;
        vector<int> indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0) q.push(adj[node][i]);
                
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
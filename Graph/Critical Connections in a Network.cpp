class Solution
{
private:
    void DFS_TarjansAlgo(int node,int parent,vector<bool>& visited,vector<int> adj[],vector<int>& insertionTime,vector<int>& lowestTime,vector<vector<int>>& ans,int &timer)
    {
        visited[node] = true;
        // initially insertion/discovery time & the lowest time for the node will be equal to timer only
        insertionTime[node] = lowestTime[node] = timer;
        timer++;
        for(auto nbr:adj[node])
        {
            if(nbr == parent) continue;

            if(!visited[nbr])
            {
                DFS_TarjansAlgo(nbr,node,visited,adj,insertionTime,lowestTime,ans,timer);
                // after the end of the DFS call for the nbr 
                lowestTime[node] = min(lowestTime[node],lowestTime[nbr]);
                // 2nd thing is we need to check that this edge is a bridge edge or not
                if(lowestTime[nbr] > insertionTime[node])
                {
                    ans.push_back({node,nbr});
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node],lowestTime[nbr]);
            }
        }
        
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        // here after reading the problem statement we can clearly observe that ve need to find the bridges not the bridges count but the edge of bridge
        // here we have edges we need to create adjacency list from it
        vector<int> adj[n];
        for(auto edge:connections)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // --------------------------- STEP 1: Initial Requirements

        // we need a insertion time array or we can say discovery time array
        vector<int> insertionTime(n,-1);
        // we need a lowest time array in which we can reach array that node
        vector<int> lowestTime(n,-1);
        // we also need a visited array to keep track which node is already visited
        vector<bool> visited(n,false);
        // we need an answer to return 
        vector<vector<int>> ans;
        // we need a timer also 
        // initially we are taking timer as 1 i.e. first DFS for node 0 will be called at time 1
        int timer = 1;

        // ---------------------------- STEP 2: Perform DFS & while returning check if parents lowest time is getting updated or not by child & then check if that node can be a bridge node or not 
        // an bridge condition will be :
        // if(low[nbr] > insertionTime[node]) i.e. if connection broken nbr cant reach node so this is a bridge conditon and push this in the answer

        // here all are connected components so we do not need to worry about more than one components of the Graph so we will once call DFS for the source node it will visit whole Graph
        DFS_TarjansAlgo(0,-1,visited,adj,insertionTime,lowestTime,ans,timer);

        return ans;
    }
};
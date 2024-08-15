class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //dijeskstra no wrt distance tho preference isthe wrong answer
        // stops based undali priority
        queue<pair<int,pair<int,int>>> q;
        //stops,node,distance
        //stopa anevi linear gaane increase avthadhi so queue is enough
        q.push({0,{src,0}});
        vector<int> dist(n,1e8);
        dist[src]=0;
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int k_got=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(k_got>k) continue;
            for(auto child : adj[node]){
                if(child.second+dis < dist[child.first]){
                    dist[child.first]=child.second+dis;
                    q.push({k_got+1,{child.first,dist[child.first]}});
                }
            }
        }
        if(dist[dst]==1e8) return -1;
        return dist[dst];
    }
};
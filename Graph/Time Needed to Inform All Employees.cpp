class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        // directed graph
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adjList[manager[i]].push_back(i);
            }
        }

        // bfs
        queue<pair<int,int>> q;
        q.push({0,headId});
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                auto curr=q.front();
                q.pop();
                int timePassed=curr.first;
                ans=max(ans,timePassed);
                int timeToPass=informTime[curr.second];
                if(timeToPass==0) continue; // end node reached
                for(int adjNode:adjList[curr.second]){
                    q.push({timePassed+timeToPass,adjNode});
                }
            }
        }
        return ans;
    }
};
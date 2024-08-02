class Solution {
public:
    int mctFromLeafValues(vector<int>& a) {
        vector<int>adj[16];
        int n = a.size();
        // Store the positions of every value
        for(int i=0; i<n; i++){
            adj[a[i]].push_back(i); 
        }
        vector<int>done(n,0);
        int ans = 0;
        for(int j=1; j<=15; j++){
            if(adj[j].size()==0) continue;
            vector<int>v=adj[j];
            for(int i=0; i<v.size(); i++){
                int idx = v[i];
                int left = idx-1;
                int right = idx+1;
                //finding which leftmost and rightmost is free;
                while(left>=0 && done[left]) left--; 
                while(right<n && done[right]) right++; 
                int mx = 100;
                // checking that it exists or not
                if(left>=0) mx = min(mx,a[left]); 
                if(right<n) mx = min(mx,a[right]); 
                if(mx!=100)ans+=mx*j;
                done[v[i]]=1; // marking that this index is done.
            }
        }
        return ans;
    }
};
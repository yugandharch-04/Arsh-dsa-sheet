class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(points[j][0]-points[i][0]>k) break;
                ans=max(ans,points[i][1]+points[j][1]+points[j][0]-points[i][0]);
            }
        }
        return ans;
    }
};
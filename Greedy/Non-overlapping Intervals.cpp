class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        for(auto ot : intervals) cout<< ot[0]<<" "<<ot[1]<<endl;
        int count=intervals.size()-1;
        int i=0;
        for(int j=1;j<intervals.size();j++){
            if(intervals[j][0]>=intervals[i][1]){
                count--;
                i=j;
            }
            else{
                intervals[i][1]=min(intervals[i][1],intervals[j][1]);
            }
        }
        return count;
    }
};
class Solution {
public:
    void solve(vector<int> &arr, int target,int ind, vector<int>& temp,set<vector<int>> &ans){
        if(target==0){
            ans.insert(temp);
            return;
        }
        if(ind>=arr.size()){
            return;
        }
        if(target<0){
            return;
        }
        if(target<arr[ind]) return;
        temp.push_back(arr[ind]);
        solve(arr,target-arr[ind],ind+1,temp,ans);
        temp.pop_back();
        while(ind+1<arr.size() and arr[ind]==arr[ind+1]) ind++;
        solve(arr,target,ind+1,temp,ans);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,0,temp,ans);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
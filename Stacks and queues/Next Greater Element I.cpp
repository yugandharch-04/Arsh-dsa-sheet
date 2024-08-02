class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=nums2.size()-1;i>=0;i--){
    if(st.empty()){
        st.push(nums2[i]);
        mp[nums2[i]]=-1;
    }
            else{
                while(!st.empty() && st.top()<nums2[i]){
         st.pop();           
                }
                if(st.empty()){
                    st.push(nums2[i]);
                    mp[nums2[i]]=-1;
                }
                else{
                    mp[nums2[i]]=st.top();
                    st.push(nums2[i]);
    }
            }
        }
        vector<int> ans;
        for(auto num :nums1){
ans.push_back(mp[num]);
        }
        return ans;
    }
};
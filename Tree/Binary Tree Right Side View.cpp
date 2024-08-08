/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        ans.push_back(root->val);
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode * dummy=q.front();
                q.pop();
                if(dummy->left!=NULL) q.push(dummy->left);
                if(dummy->right!=NULL) q.push(dummy->right);
            }
            if(!q.empty()) ans.push_back(q.back()->val);
        }
        return ans;
    }
};
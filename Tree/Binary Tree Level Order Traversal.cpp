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

/* Iterative */
class Solution {
public:
    vector<vector<int>> output;

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            int l=q.size();
            vector<int> temp;
            for(int i=0;i<l;i++){
                TreeNode* t=q.front();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.push_back(t->val);
                q.pop();

            }
            output.push_back(temp);
        }

        return output;
    }

   
};



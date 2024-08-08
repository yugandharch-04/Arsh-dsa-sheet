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
    bool solve(TreeNode* p, TreeNode* q){
        TreeNode * ptr=p;
        TreeNode*qtr=q;
        if(ptr==NULL && qtr==NULL) return true;
        if(ptr==NULL || qtr==NULL) return false;

        if(ptr->val!=qtr->val) return false;
        bool rgt=true;
        rgt&=solve(ptr->left,qtr->right);
        rgt&=solve(ptr->right,qtr->left);
        return rgt;
    }
    bool isSymmetric(TreeNode* root) {
        if(root->right==NULL &&root->left==NULL) return true;
        if(root->right==NULL ||root->left==NULL) return false;
        return solve(root->left,root->right);
    }
};
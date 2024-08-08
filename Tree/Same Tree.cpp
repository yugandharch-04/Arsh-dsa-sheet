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
    bool solve(TreeNode* ptr, TreeNode* qtr){
        
        if(ptr==NULL && qtr==NULL) return true;
        if(ptr==NULL || qtr==NULL) return false;

        if(ptr->val!=qtr->val) return false;
        bool rgt=true;
        rgt&=solve(ptr->left,qtr->left);
        rgt&=solve(ptr->right,qtr->right);
        return rgt;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return solve(p,q);

    }
};
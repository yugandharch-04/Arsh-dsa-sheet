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
    bool isequal(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        if(root->val==subRoot->val){
            return (isequal(root->left,subRoot->left) && isequal(root->right,subRoot->right));
        }
        return false;

        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        bool canBe=false;
        if(root->val==subRoot->val){
            canBe= (isequal(root->left,subRoot->left) && isequal(root->right,subRoot->right));
        }
        return (canBe || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));

        
    }
};
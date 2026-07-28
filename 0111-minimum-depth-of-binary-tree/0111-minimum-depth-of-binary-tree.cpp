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
    int height(TreeNode* root){
        if(root==NULL)
        return 1e9;
        if(root->left==NULL && root->right==NULL)
        return 1;
        int lh=height(root->left);
        int rh=height(root->right);  
        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        return height(root);
    }
};
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
    int preorder(TreeNode* root, TreeNode* root1){
        if(root==NULL && root1==NULL)
        return 1;
        if(root==NULL || root1==NULL)
        return 0; 
        if(root->val!=root1->val) 
        return 0;
        int l=preorder(root->left,root1->left);
        int r=preorder(root->right,root1->right);
        if(l==0 || r==0) return 0;
        return 1;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p,q);
    }
};
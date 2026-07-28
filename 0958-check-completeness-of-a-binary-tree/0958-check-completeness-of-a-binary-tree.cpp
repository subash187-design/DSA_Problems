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
    int count(TreeNode* root){
        if(root==NULL)
        return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool rec(TreeNode* root,int i,int n){
        if(root==NULL){
            return true;
        }
        if(i>=n) 
        return false;

        return rec(root->left,2*i+1,n) && rec(root->right,2*i+2,n);
    }
    bool isCompleteTree(TreeNode* root) {
        int n=count(root);
        return rec(root,0,n);
    }
};
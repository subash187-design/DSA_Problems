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
    int ans=0;

    int rec(TreeNode* root){
        if(root==NULL)
        return 0;
        int lt=rec(root->left);
        int rt=rec(root->right);
        int l=0,r=0;
        if(root->left && root->left->val==root->val)
        l=lt+1;
        if(root->right && root->right->val==root->val)
        r=rt+1;
        ans=max(ans,l+r);
        return max(l,r);
        
    }
    int longestUnivaluePath(TreeNode* root) {
     if(root==NULL)
     return 0;
     rec(root);  
     return ans; 
    }
};
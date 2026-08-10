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
        if(root->left && root->left->val==root->val)
        lt=lt+1;
        else
        lt=0;
        if(root->right && root->right->val==root->val)
        rt=rt+1;
        else
        rt=0;
        ans=max(ans,lt+rt);
        return max(lt,rt);
        
    }
    int longestUnivaluePath(TreeNode* root) {
     if(root==NULL)
     return 0;
     rec(root);  
     return ans; 
    }
};
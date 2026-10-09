/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
       if(root == NULL || root == p || root == q)
        return root; 
       int curr = root -> val;
       if(p->val < curr && q-> val < curr){
        return lca(root->left,p,q);
       }
       else if(p->val > curr && q->val > curr){
        return lca(root->right,p,q);
       }
       return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
        return root;
        return lca(root,p,q);
    }
};
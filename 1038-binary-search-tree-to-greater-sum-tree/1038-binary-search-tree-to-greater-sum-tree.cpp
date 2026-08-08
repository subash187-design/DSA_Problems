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
    int sum=0;
    void inorderReverse(TreeNode* root){
        if(root==NULL)
        return;
        inorderReverse(root->right);
        sum=sum+root->val;
        root->val=sum;
        inorderReverse(root->left);
       
    }
    TreeNode* bstToGst(TreeNode* root) {
      inorderReverse(root); 
      return root; 
    }
};
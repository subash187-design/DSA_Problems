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
    int mn=INT_MAX;
    int flag=0;
    int prev=0;
    void inorder(TreeNode* root){
        if(root==NULL)
        return;
        inorder(root->left);
        if(flag==0){
            prev=root->val;
            flag=1;
        }
        else{
            int k=abs(prev-root->val);
            mn=min(mn,k);
            prev=root->val;
        }
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
      if(root==NULL)
      return 0;
      inorder(root);
      return mn==INT_MAX?-1:mn; 
    }
};
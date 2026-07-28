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
    int res=INT_MIN;
    int rec(TreeNode* root){
        if(root==NULL)
        return 0;
        int lh=rec(root->left);
        int rh=rec(root->right);
        res=max({res,root->val,lh+rh+root->val,lh+root->val,rh+root->val});
        cout<<root->val<<" "<<res<<endl;
        return max(root->val,root->val+max(lh,rh));
    }
    int maxPathSum(TreeNode* root) {
      if(root==NULL)
      return 0;
      rec(root);
      return res;
        
    }
};
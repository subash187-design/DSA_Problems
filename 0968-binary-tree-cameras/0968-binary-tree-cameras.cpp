/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };//un - 0 oncam 1 cov 2 
 */
class Solution {
public:
    int ans=0;
    int rec(TreeNode* root){
        if(root==NULL) return 2;
        int lt=rec(root->left);
        int rt=rec(root->right);
        if(lt==2 && rt==2)
        return 0;
        else if(lt==0 || rt==0){
        ans++;
        return 1;
        }
        return 2;
       
    }
    int minCameraCover(TreeNode* root) {
      if(root==NULL)
      return 0;
      int k=rec(root);
      if(k==0 )
      return 1+ans;
      return ans;  
    }
};
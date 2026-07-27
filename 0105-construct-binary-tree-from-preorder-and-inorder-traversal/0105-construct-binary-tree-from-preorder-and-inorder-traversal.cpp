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
    int rt=0;
    unordered_map<int,int>mp;
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int i,int j){
        if(i>j)
        return NULL;
        TreeNode* root=new TreeNode(preorder[rt]);
        int m=mp[preorder[rt]];
        rt++;
        root->left=tree(preorder,inorder,i,m-1);
        root->right=tree(preorder,inorder,m+1,j);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n=preorder.size();
      int m=inorder.size();
      if(n==0 && m==0) 
      return NULL;
      for(int i=0;i<m;i++){
        mp[inorder[i]]=i;
      }
      return tree(preorder,inorder,0,m-1);
    }
};
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
    TreeNode* rec(unordered_map<int,unordered_map<int,int>>&mp,int rt){
        
        int lt=mp[rt][1];
        int rg=mp[rt][0];
        TreeNode* root=new TreeNode(rt);
        if(lt==0) root->left=NULL;
        else root->left=rec(mp,lt);
        if(rg==0) root->right=NULL;
        else root->right=rec(mp,rg);
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      unordered_map<int,unordered_map<int,int>>mp;
      vector<int>vis(100001,0);
      for(int i=0;i<descriptions.size();i++){
        int a=descriptions[i][0];
        int b=descriptions[i][1];
        int c=descriptions[i][2];
        
        vis[b]=1;
        mp[a][c]=b;
      } 
      int root;
     
      for(int i=0;i<descriptions.size();i++){
        if(vis[descriptions[i][0]]==0){
        root=descriptions[i][0];
        break;
        }
      }
      return rec(mp,root);
    }
};
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
    unordered_map<int,int>mp;
    TreeNode* build(vector<int>&inorder,int inStart,int inEnd,vector<int>&preorder,int preStart,int preEnd){
        if(inStart>inEnd || preStart>preEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[preorder[preStart]];
        int lt=inRoot-inStart;
        root->left=build(inorder,inStart,inRoot-1,preorder,preStart+1,preStart+lt);
        root->right=build(inorder,inRoot+1,inEnd,preorder,preStart+lt+1,preEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if(inorder.size()!=preorder.size())
        return NULL;
       for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
       } 
       return build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);  
    }
};
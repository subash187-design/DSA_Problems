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
    TreeNode* build(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int poStart,int poEnd){
        if(inStart>inEnd || poStart>poEnd) return NULL;
        TreeNode* root=new TreeNode(postorder[poEnd]);
        int inRoot=mp[postorder[poEnd]];
        int lt=inRoot-inStart;
        root->left=build(inorder,inStart,inRoot-1,postorder,poStart,poStart+lt-1);
        root->right=build(inorder,inRoot+1,inEnd,postorder,poStart+lt,poEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       if(inorder.size()!=postorder.size())
        return NULL;
       for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
       } 
       return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};
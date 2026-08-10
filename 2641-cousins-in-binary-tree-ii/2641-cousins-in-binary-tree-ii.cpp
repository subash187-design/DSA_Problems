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
    void rec(TreeNode* root,int lvl){
        if(root==NULL)
        return;
        mp[lvl]=mp[lvl]+root->val;
        rec(root->left,lvl+1);
        rec(root->right,lvl+1);
    }
    void rec1(TreeNode* root,int lvl){
        int x=mp[lvl+1];
        int y=0;
        if(root->left)
        y+=root->left->val;
        if(root->right)
        y+=root->right->val;
        x=x-y;
        if(root->left){
        root->left->val=x;
        rec1(root->left,lvl+1);
        }
        if(root->right){
        root->right->val=x;
        rec1(root->right,lvl+1);
        }


    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)
        return NULL;
        rec(root,0);
        root->val=0;
        rec1(root,0);
        return root;
    }
};
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
    int mxlvl=0;
    void rec(TreeNode* root,int lvl){
        if(root==NULL)
        return;
        mp[lvl]+=root->val;
        mxlvl=max(lvl,mxlvl);
        rec(root->left,lvl+1);
        rec(root->right,lvl+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        rec(root,0);
        return mp[mxlvl];
    }
};
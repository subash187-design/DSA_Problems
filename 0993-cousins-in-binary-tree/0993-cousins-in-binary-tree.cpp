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
    unordered_map<int,pair<int,int>>par;
    void rec(TreeNode* root,int lvl){
        if(root==NULL)
        return;
        if(root->left)
        {
            par[root->left->val]={root->val,lvl+1};
            rec(root->left,lvl+1);
        }
        if(root->right){
           par[root->right->val]={root->val,lvl+1};
            rec(root->right,lvl+1); 
        }
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
        return true;
        if(x==y) return false;
        rec(root,1);
        if(par[x].first!=par[y].first && par[x].second==par[y].second)
        return true;
        return false;
    }
};
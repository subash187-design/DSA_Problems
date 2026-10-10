/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int rec(TreeNode* root) {
        if (root == NULL)
            return 0;
        if(mp.find(root) != mp.end())
        return mp[root];
        int take = root->val;
        if (root->left) {
            take += rec(root->left->left) + rec(root->left->right);
        }
        if (root->right) {
            take += rec(root->right->left) + rec(root->right->right);
        }
        int nottake = rec(root->left) + rec(root->right);
        return mp[root] = max(take, nottake);
    }
    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        return rec(root);
    }
};
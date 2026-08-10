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
    int cnt=0;
    void inorder(TreeNode* root,int mx){
        if(root==NULL)
        return;
        if(root->val>=mx){
            cnt++;
        }
        inorder(root->left,max(mx,root->val));
        inorder(root->right,max(mx,root->val));
    }
    int goodNodes(TreeNode* root) {
    if(root==NULL)
    return 0;
    inorder(root,root->val);
     return cnt;   
    }
};
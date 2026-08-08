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
    TreeNode* first=NULL;
    TreeNode* prev=NULL;
    TreeNode* mid=NULL;
    TreeNode* last=NULL;
    void inorder(TreeNode* root){
        if(root==NULL)
        return;
        inorder(root->left);
        if(prev!=NULL){
            if(prev->val>root->val && first==NULL && mid==NULL){
                first=prev;
                mid=root;
            }
            else if(prev->val>root->val)
            last=root;
        }

        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && last)
        swap(first->val,last->val);
        else if(first && mid)
        swap(first->val,mid->val);
    }
};
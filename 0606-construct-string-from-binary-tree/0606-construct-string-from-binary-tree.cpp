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
    void rec(TreeNode* root, string& temp) {
        if (root == NULL)
            return ;
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL)
            return;
        if (root->right != NULL) {
            temp += '(';
            rec(root->left, temp);
            temp += ')';
            temp += '(';
            rec(root->right, temp);
            temp += ')';
        }
        else{
            temp += '(';
            rec(root->left, temp);
            temp += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string temp = "";
        rec(root, temp);
        return temp;
    }
};
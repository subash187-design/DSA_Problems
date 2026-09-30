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
    string rec(TreeNode* root, string& temp) {
        if (root == NULL)
            return "";
        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL)
            return temp;
        if (root->right != NULL) {
            temp += '(';
            string left = rec(root->left, temp);
            temp += ')';
            temp += '(';
            string right = rec(root->right, temp);
            temp += ')';
        }
        else{
            temp += '(';
            string left = rec(root->left, temp);
            temp += ')';
        }

        return temp;
    }
    string tree2str(TreeNode* root) {
        string temp = "";
        return rec(root, temp);
    }
};
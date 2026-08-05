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
    vector<string>res;
    void rec(TreeNode* root,string s){
        if(root==NULL)
        return;
        if(s=="")
        s+=to_string(root->val);
        else{
        s=s+'-'+'>';
        s+=to_string(root->val);
        }
        if(root->left==NULL && root->right==NULL)
        {
            res.push_back(s);
            return ;
        }
        rec(root->left,s);
        rec(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
        return {};
        string s="";
        if(root->left==NULL && root->right==NULL){
        s+=to_string(root->val);
        res.push_back(s);
        return res;
        }
        rec(root,s);
        return res;
    }
};
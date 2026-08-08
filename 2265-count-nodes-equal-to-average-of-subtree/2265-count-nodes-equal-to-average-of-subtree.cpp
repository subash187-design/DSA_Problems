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
    pair<int,int> rec(TreeNode* root){
        if(root==NULL)
        return {0,0};
        pair<int,int>a,b;
        a=rec(root->left);
        b=rec(root->right);
        int x,y;
        x=a.first+b.first+root->val;
        y=1+a.second+b.second;
        if((x/y)==root->val)
        cnt++;
        return {x,y};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)
        return 0;
        rec(root);
        return cnt;
    }
};
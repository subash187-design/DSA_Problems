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
    int leftheight(TreeNode* root){
        int ans=0;
        while(root!=NULL){
            ans++;
            root=root->left;
        }
        return ans;
    }
    int rightheight(TreeNode* root){
        int ans=0;
        while(root!=NULL){
            ans++;
            root=root->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
     if(root==NULL)
     return 0;
     int lh=leftheight(root);
     int rh=rightheight(root);
     cout<<root->val<<" "<<lh<<" "<<rh<<endl;
     if(lh==rh)
     return (1<<lh)-1;
     else
     return 1+countNodes(root->left)+countNodes(root->right);

    }
};
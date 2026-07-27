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
    int dia=0;
    int diameter(TreeNode* root){
     if(root==NULL) return 0;
     int lt=diameter(root->left);
     int rt=diameter(root->right);
     dia=max(dia,lt+rt);
     return 1+max(lt,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=0;
        diameter(root);
       return dia;
    }
};
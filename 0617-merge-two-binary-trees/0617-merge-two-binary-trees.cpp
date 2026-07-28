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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
     if(root1==NULL && root2==NULL){
        return NULL;
     }
     int sum=0;   
     if(root1==NULL){
        sum+=root2->val;
        TreeNode* temp=new TreeNode(sum);
        temp->left=root2->left;
        temp->right=root2->right;
         return temp;
     }
     else if(root2==NULL){
        sum+=root1->val;
        TreeNode* temp=new TreeNode(sum);
        temp->left=root1->left;
        temp->right=root1->right;
         return temp;
     }
     else{
        sum+=root1->val+root2->val;
     TreeNode* temp=new TreeNode(sum);
     temp->left=mergeTrees(root1->left,root2->left);
     temp->right=mergeTrees(root1->right,root2->right);
      return temp;
     }
    
    }

};
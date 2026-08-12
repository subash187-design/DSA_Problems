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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(root==NULL)
       return NULL;
       if(depth==1){
        TreeNode* newRoot=new TreeNode(val);
        newRoot->left=root;
        return newRoot;
       } 
       queue<TreeNode*>que;
       que.push(root);
       int lvl=1;
       while(!que.empty()){
        int n=que.size();
        for(int i=0;i<n;i++){
         TreeNode* k=que.front();
         que.pop();
        if(lvl+1==depth){
           
            TreeNode* lt=k->left;
            TreeNode* rt=k->right;
            k->left=new TreeNode(val);
            k->right=new TreeNode(val);
            k->left->left=lt;
            k->right->right=rt;
        }
        if(k->left)
        que.push(k->left);
        if(k->right)
        que.push(k->right);
        }
        lvl=lvl+1;
       }
       return root;
    }
};
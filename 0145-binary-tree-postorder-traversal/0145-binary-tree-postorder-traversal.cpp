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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
        return {};
       vector<int>res;
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
        TreeNode* temp=st.top();
        st.pop();
        if(temp->left!=NULL)
        st.push(temp->left);
        if(temp->right!=NULL)
        st.push(temp->right);
        res.push_back(temp->val);
        
       }
       reverse(res.begin(),res.end());
       return res; 
    }
};
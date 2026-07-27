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
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*>st;
        st.push(root);
        TreeNode*temp=root;
        while(!st.empty()){
            while(temp->left!=NULL){
                st.push(temp->left);
                temp=temp->left;
        
            }
            TreeNode* lt=st.top();
            st.pop();
            res.push_back(lt->val);
            if(lt->right!=NULL){
            st.push(lt->right);
            temp=lt->right;
            }
        }
        return res;
    }
};
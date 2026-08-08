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
class bstIterator{
    public:
      stack<TreeNode*>st;
      bool reverse;
      void insert(TreeNode*root){
        if(root==NULL)
        return;
        if(reverse){
            while(root!=NULL){
            st.push(root);
            root=root->right;
            }
        }
        else{
           while(root!=NULL){
            st.push(root);
            root=root->left;
            } 
        }
      }
      bstIterator(TreeNode* root,bool reverse){
        this->reverse=reverse;
        insert(root);
      }
      bool hasNext(){
        return st.size()>0;
      }
      int next(){
        TreeNode* top=st.top();
        st.pop();
        if(reverse){
            if(top->left!=NULL)
            insert(top->left);
        }
        else{
            if(top->right!=NULL)
            insert(top->right);
        }
        return top->val;
      }


};
class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        return false;
        bstIterator lt(root,false);
        bstIterator rt(root,true);
        int a=lt.next();
        int b=rt.next();
        if(a+b==k && a!=b) return true;
        while(lt.hasNext() && rt.hasNext() && a!=b){
            if(a+b==k)
            return true;
            if(a+b<k)
            a=lt.next();
            else
            b=rt.next();
        }
        return false;
    }
};
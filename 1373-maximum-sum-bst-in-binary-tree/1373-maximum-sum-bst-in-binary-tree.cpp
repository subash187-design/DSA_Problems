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
class Node{
    public:
    int mx,mn,sum;
    Node(int mx,int mn,int sum){
        this->mx=mx;
        this->mn=mn;
        this->sum=sum;
    }
};
class Solution {
public:
    int ans=0;
    Node rec(TreeNode* root){
        if(root==NULL)
        return Node(INT_MIN,INT_MAX,0);
        auto lt=rec(root->left);
        auto rt=rec(root->right);
        if(lt.mx<root->val && root->val<rt.mn){
            ans=max({ans,lt.sum,rt.sum,root->val+lt.sum+rt.sum});
            return Node(max(root->val,rt.mx),min(root->val,lt.mn),lt.sum+rt.sum+root->val);    
        }
        
        return Node(INT_MAX,INT_MIN,max(lt.sum,rt.sum));


    }
    int maxSumBST(TreeNode* root) {
       if(root==NULL)
       return 0;
       int res=rec(root).sum;
       return ans; 
    }
};
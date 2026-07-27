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
    int rt=0;
    unordered_map<int,int>mp;
    TreeNode* tree(vector<int>& preorder, vector<int>& postorder,int i,int j){
        if(i>j || rt>preorder.size()) return NULL;
        TreeNode* root =new TreeNode(preorder[rt]);
        
        int m=mp[preorder[rt]];
        rt++;
        if(i==j) return root;
        int k;
        if(rt>=preorder.size())
        k=preorder.size()-1;
        else
        k=mp[preorder[rt]];

        cout<<root->val<<endl;
        root->left=tree(preorder,postorder,i,k);
        root->right=tree(preorder,postorder,k+1,m-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       int n=preorder.size();
       int m=postorder.size();
       if(n==0 && m==0)
       return NULL;
       for(int i=0;i<n;i++){
        mp[postorder[i]]=i;
       }
       return tree(preorder,postorder,0,m-1); 
    }
};
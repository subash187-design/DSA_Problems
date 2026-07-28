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
    map<int,int>res;
    bool flag=true;
    void func(TreeNode* root,int ind){
        if(ind >= 203){
        return;
        }
        if(root==NULL){
            res[ind]=-1;
            return;
        }
        res[ind]=root->val;
        func(root->left,ind*2+1);
        func(root->right,ind*2+2);

    }
    bool isCompleteTree(TreeNode* root) {
        func(root,0);
        int flag=0;
        for(auto i:res){
            if(i.second==-1 && flag==0){
            flag=1;
            continue;
            }
            else if(i.second!=-1 && flag==1){
                return false;
            }
            
        }
        return true;

    }
};
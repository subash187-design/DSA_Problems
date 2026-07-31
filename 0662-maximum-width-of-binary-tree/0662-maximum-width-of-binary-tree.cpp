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
    int widthOfBinaryTree(TreeNode* root) {
      if(root==NULL)
      return 0;
      queue<pair<TreeNode*,long long>>que;
      que.push({root,0});
      int ans=0;
      while(!que.empty()){
        int first=0;
        int last=0;
        int n=que.size();
        long long mn=que.front().second;
        for(int i=0;i<n;i++){
            TreeNode* temp=que.front().first;
            long long k=que.front().second;
            que.pop();
            k=k-mn;
            if(i==0) first=k;
            if(i==n-1) last=k;
            if(temp->left!=NULL){
                que.push({temp->left,2*k+1});
            }
            if(temp->right!=NULL){
                que.push({temp->right,2*k+2});
            }
        }
        ans=max(ans,last-first+1);
      }
      return ans;  
    }
};
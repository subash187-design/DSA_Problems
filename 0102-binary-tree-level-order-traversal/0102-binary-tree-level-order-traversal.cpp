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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
       vector<vector<int>>res;
       queue<pair<TreeNode*,int>>que;
       que.push({root,0});
       while(!que.empty()){
          TreeNode* temp=que.front().first;
          int k=que.front().second;
          que.pop();
           if (k >= res.size()) {
              res.push_back({}); 
          }
          res[k].push_back(temp->val);
         
          if(temp->left!=NULL)
            que.push({temp->left,k+1});
          if(temp->right!=NULL)
            que.push({temp->right,k+1});
       }
       return res; 
    }
};
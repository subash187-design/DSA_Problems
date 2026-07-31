/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&par){
        queue<TreeNode*>que;
        que.push(root);
        par[root]=NULL;
        while(!que.empty()){
            TreeNode* temp=que.front();
            que.pop();
            if(temp->left!=NULL){
                par[temp->left]=temp;
                que.push({temp->left});
            }
            if(temp->right!=NULL){
                par[temp->right]=temp;
                que.push({temp->right});
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      if(root==NULL)
      return {};
      unordered_map<TreeNode*,TreeNode*>par;
      vector<int>res;
      queue<TreeNode*>que;
      unordered_map<TreeNode*,bool>vis;
      int lvl=0;
      parent(root,par);
      que.push(target);
      vis[target]=true;
      while(!que.empty()){
        int n=que.size();
        if(lvl==k) break;
        lvl++;
        
        for(int i=0;i<n;i++){
            TreeNode* temp=que.front();
            que.pop();
            if(par[temp]!=NULL && vis[par[temp]]==false){
                que.push(par[temp]);
                vis[par[temp]]=true;
            }
            if(temp->left!=NULL && vis[temp->left]==false){
            que.push(temp->left);
            vis[temp->left]=true;
            }
            if(temp->right!=NULL&& vis[temp->right]==false){
            que.push(temp->right);
            vis[temp->right]=true;
            }
        }
      }
      while(!que.empty()){
        TreeNode* temp=que.front();
        res.push_back(temp->val);
        que.pop();
      }
      return res;
    }
};
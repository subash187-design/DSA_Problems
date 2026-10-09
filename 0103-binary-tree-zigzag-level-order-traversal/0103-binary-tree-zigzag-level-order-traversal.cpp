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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
        return {};
        vector<vector<int>>res;
        int lvl = 0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            vector<int>dup;
            for(int i = 0; i < n; i++){
                    TreeNode* curr = que.front();
                    que.pop();
                    dup.push_back(curr->val);
                    if(curr->left)
                    que.push(curr->left);
                    if(curr->right)
                    que.push(curr->right);
                }
            if(lvl % 2 == 0){
               res.push_back(dup); 
            }
            else{
                reverse(dup.begin(),dup.end());
                res.push_back(dup);
            }
            lvl++;
        }
        return res;
    }
};
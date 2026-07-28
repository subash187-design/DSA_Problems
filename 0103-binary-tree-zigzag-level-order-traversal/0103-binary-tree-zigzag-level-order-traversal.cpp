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
       if(root==NULL)
       return {};
       vector<vector<int>>res;
       queue<TreeNode*>que;
       que.push(root);
       bool flag=0;
       while(!que.empty()){
        int n=que.size();
        vector<int>ans(n);
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            TreeNode* temp=que.front();
            que.pop();
            int k=flag==0?i:n-i-1;
            ans[k]=temp->val;
            if(temp->left!=NULL)
            que.push(temp->left);
            if(temp->right!=NULL)
            que.push(temp->right);
        }
        res.push_back(ans);
        flag=!flag;
       }
       return res;

    }
};
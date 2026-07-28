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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       map<int,map<int,multiset<int>>>mp;
       queue<pair<TreeNode*,pair<int,int>>>que;
       que.push({root,{0,0}});
       while(!que.empty()){
        TreeNode* node=que.front().first;
        int ver=que.front().second.first;
        int lvl=que.front().second.second;
        que.pop();
        mp[ver][lvl].insert(node->val);
        if(node->left!=NULL)
        que.push({node->left,{ver-1,lvl+1}});
        if(node->right!=NULL)
        que.push({node->right,{ver+1,lvl+1}});
       } 
       vector<vector<int>>res;
       for(auto i:mp){
        vector<int>temp;
        cout<<i.first<<endl;
        for(auto j:i.second){
            cout<<j.first<<" "<<j.second.size()<<endl;
            for(auto k:j.second){
                temp.push_back(k);
            }
        }
        res.push_back(temp);
       }
       return res;


    }
};
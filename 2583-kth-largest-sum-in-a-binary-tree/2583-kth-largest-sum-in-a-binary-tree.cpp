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
    unordered_map<int,long long>mp;
    void rec(TreeNode* root,int lvl){
        if(root==NULL)
        return;
        mp[lvl]+=root->val;
        rec(root->left,lvl+1);
        rec(root->right,lvl+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL)
        return 0;
        rec(root,0);
        multiset<long long,greater<long long>>res;
        for(auto i:mp){
        res.insert(i.second);
        }
        int i=0;
        for(auto x:res)
        {
            if(i+1==k) return x;
            i++;
        }
        return -1;
    }
};
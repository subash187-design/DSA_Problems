/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    vector<int> res;
public:
    int  perfect(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh=perfect(root->left);
        int rh=perfect(root->right);
        if (lh == rh && lh!=-1) {
            int h = (1 << (lh+1)) - 1;
            res.push_back(h);
            return lh+1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        perfect(root);
        sort(res.begin(), res.end());
        int cnt = 0;
        for (int i = res.size() - 1; i >= 0; i--) {
            cnt++;
            if(cnt==k) return res[i];
        }
        return -1;
    }
};
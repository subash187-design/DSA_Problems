/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            vector<int> lvl;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = que.front();
                que.pop();
                lvl.push_back((curr->val));
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }
            for (int i = 0; i < n - 1; i++) {
                int min_ind = i;
                for (int j = i + 1; j < n; j++) {
                    if (lvl[j] < lvl[min_ind]) {
                        min_ind = j;
                    }
                }
                if(min_ind != i){
                    swap(lvl[min_ind],lvl[i]);
                    res++;
                }
            }
        }
        return res;
    }
};
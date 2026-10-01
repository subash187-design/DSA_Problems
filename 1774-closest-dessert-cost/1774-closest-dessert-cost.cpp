class Solution {
public:
    int n;
    int rec(int i, int target, vector<int>& toppingCosts) {
        if (i >= toppingCosts.size())
            return 0;
        int ans = 0;
        int mn = 1e9;
        for (int k = 0; k < 2; k++) {
            int temp = toppingCosts[i] * (k + 1);
            int curr = temp + rec(i + 1, target - temp, toppingCosts);
            int diff = abs(target - curr);
            if (diff < mn) {
                ans = curr;
                mn = diff;
            } else if (diff == mn && curr < ans) {
                ans = curr;
            }
        }
        int curr = rec(i + 1, target, toppingCosts);
        int diff = abs(target - curr);
        if (diff < mn) {
            ans = curr;
            mn = diff;
        } else if (diff == mn && curr < ans) {
            ans = curr;
        }
        return ans;
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts,
                    int target) {
        int res = 0;
        int mn = 1e9;
        n = baseCosts.size();
        for (int i = 0; i < n; i++) {
            int curr =
                baseCosts[i] + rec(0, target - baseCosts[i], toppingCosts);
            int k = abs(target - curr);
            if (k < mn) {
                res = curr;
                mn = k;
            } else if (k == mn && curr < res) {
                res = curr;
            }
        }
        return res;
    }
};
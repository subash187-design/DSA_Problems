class Solution {
public:
    vector<int> sortable;
    void solve(int n) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sortable.push_back(i);
            }
        }
    }
    bool checker(vector<int>& orig, vector<int>& temp) {
        int n = orig.size();
        vector<int> dup(orig.begin(), orig.end());
        for(int i : orig)
        dup.push_back(i);
        auto it = search(dup.begin(), dup.end() , temp.begin() , temp.end());
        return it != dup.end();
    }
    bool check(int k, vector<int>& nums, vector<int>& s) {
        int n = nums.size();
        for (int l = 0; l < n; l += k) {
            {
                vector<int> temp(s.begin() + l, s.begin() + l + k);
                vector<int> rotate(nums.begin() + l, nums.begin() + l + k);
                if (!checker(temp, rotate))
                    return false;
            }
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        solve(n);
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int res = 0;
        for (int i = 0; i < sortable.size(); i++) {
            if (check(sortable[i], nums, temp)) {
                res += sortable[i];
            }
        }
        return res;
    }
};
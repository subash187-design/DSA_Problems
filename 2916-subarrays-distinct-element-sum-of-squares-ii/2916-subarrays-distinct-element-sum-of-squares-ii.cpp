class segment {
public:
    int curr;
};
class Solution {
public:
    int mod = 1e9 + 7;
    vector<segment> sum;
    vector<segment> sum_sq;
    vector<segment> lz;
    void build(int node, int l, int r) {
        if (l == r) {
            sum[node].curr = 0;
            sum_sq[node].curr = 0;
            lz[node].curr = 0;
            return; 
        }
        int mid = l + (r - l) / 2;
        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);
        sum[node].curr = sum[node * 2 + 1].curr + sum[node * 2 + 2].curr;
        sum_sq[node].curr =
            sum_sq[node * 2 + 1].curr + sum_sq[node * 2 + 2].curr;
        lz[node].curr = 0;
    }
    void lazy_propogation(int ind, int l, int r, int tl, int tr, int val) {
        int len = (r - l + 1);
        if (lz[ind].curr != 0) {
            int lz_val = lz[ind].curr;
            sum_sq[ind].curr = (sum_sq[ind].curr +
                                (((2 * lz_val) % mod) * sum[ind].curr) % mod +
                                (((len * lz_val) % mod) * lz_val) % mod) %
                               mod;
            sum[ind].curr =
                (sum[ind].curr + (long long)(lz_val * len) % mod) % mod;
            if (l != r) {
                lz[ind * 2 + 1].curr =
                    (lz[ind * 2 + 1].curr + lz[ind].curr) % mod;
                lz[ind * 2 + 2].curr =
                    (lz[ind * 2 + 2].curr + lz[ind].curr) % mod;
            }
            lz[ind].curr = 0;
        }
        if (r < tl || tr < l)
            return;
        if (tl <= l && r <= tr) {
            sum_sq[ind].curr =
                (sum_sq[ind].curr + (((2 * val) % mod) * sum[ind].curr) % mod +
                 (((len * val) % mod) * val) % mod) %
                mod;
            sum[ind].curr =
                (sum[ind].curr + (long long)(val * len) % mod) % mod;
            if (l != r) {
                lz[ind * 2 + 1].curr = (lz[ind * 2 + 1].curr + val) % mod;
                lz[ind * 2 + 2].curr = (lz[ind * 2 + 2].curr + val) % mod;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        lazy_propogation(ind * 2 + 1, l, mid, tl, tr, val);
        lazy_propogation(ind * 2 + 2, mid + 1, r, tl, tr, val);

        sum[ind].curr = (sum[ind * 2 + 1].curr + sum[ind * 2 + 2].curr) % mod;
        sum_sq[ind].curr =
            (sum_sq[ind * 2 + 1].curr + sum_sq[ind * 2 + 2].curr) % mod;
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.resize(4 * n);
        sum_sq.resize(4 * n);
        lz.resize(4 * n);
        build(0, 0, n - 1);
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int last_seen = -1;
            if (mp.find(nums[i]) != mp.end())
                last_seen = mp[nums[i]];
            lazy_propogation(0, 0, n - 1, last_seen + 1, i, 1);
            res = (res + (sum_sq[0].curr)) % mod;
            mp[nums[i]] = i;
        }
        return res;
    }
};
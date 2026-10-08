class Solution {
public:
    int numSplits(string s) {
        int mask1 = 0;
        int mask2 = 0;
        int n = s.size();
        vector<int> prefixSum1(n, 0), prefixSum2(n, 0);
        prefixSum1[0] = 1;
        mask1 = mask1 | (1 << (s[0] - 'a'));
        for (int i = 1; i < n; i++) {
            if (!(mask1 & (1 << (s[i] - 'a')))) {
                prefixSum1[i] = 1 + prefixSum1[i - 1];
                mask1 = mask1 | (1 << (s[i] - 'a'));
            } else {
                prefixSum1[i] = prefixSum1[i - 1];
            }
        }
        prefixSum2[n - 1] = 1;
        mask2 = mask2 | (1 << (s[n - 1] - 'a'));
        for (int i = n - 2; i >= 0; i--) {
            if (!(mask2 & (1 << (s[i] - 'a')))) {
                prefixSum2[i] = 1 + prefixSum2[i + 1];
                mask2 = mask2 | (1 << (s[i] - 'a'));
            } else {
                prefixSum2[i] = prefixSum2[i + 1];
            }
        }
        int res = 0;
        for(int i = 0; i < n - 1; i++){
            if(prefixSum1[i] == prefixSum2[i + 1])
            res++;
        }
        return res;
    }
};
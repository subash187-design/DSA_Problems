class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        stack<pair<int, int>> st;
        int n = seq.size();
        int mx = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                cnt++;
                mx = max(mx, cnt);
            } else {
                cnt--;
            }
        }
        int k = mx / 2;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                int x = st.size();
                if (x  < k) {
                    st.push({i, 0});
                    res.push_back(0);
                } else {
                    st.push({i, 1});
                    res.push_back(1);
                }
            } else {
                int x = st.top().second;
                res.push_back(x);
                st.pop();
            }
        }
        return res;
    }
};
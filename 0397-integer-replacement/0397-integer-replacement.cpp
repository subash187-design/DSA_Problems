#define ll long long
class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<ll, ll>> que;
        que.push({n, 0});
        unordered_map<int,int>mp;
        mp[n] = 1;
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            ll num = it.first;
            ll step = it.second;
            if (num == 1)
                return step;
            if (num % 2 == 0) {
                ll newNum = num / 2;
                if (mp[newNum] == 0) {
                    mp[newNum] = 1;
                    que.push({newNum, step + 1});
                }
            } else {
                ll newNum1 = num - 1;
                ll newNum2 = num + 1;
                if (mp[newNum1] == 0) {
                    mp[newNum1] = 1;
                    que.push({newNum1, step + 1});
                }
                if (mp[newNum2] == 0) {
                    mp[newNum2] = 1;
                    que.push({newNum2, step + 1});
                }
            }
        }
        return -1;
    }
};
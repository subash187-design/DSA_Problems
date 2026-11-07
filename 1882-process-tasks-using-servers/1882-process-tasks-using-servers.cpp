class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        vector<pair<int, int>> arr(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            arr[i] = {servers[i], i};
            mp[i] = servers[i];
        }
        sort(arr.begin(), arr.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            unavailable;
        for (auto it : arr) {
            available.push({it.first, it.second});
        }
        vector<int> res;
        long long t = 0;
        for (int i = 0; i < tasks.size(); i++) {
            int time = tasks[i];
            t = max(t, (long long)i);
            while (!unavailable.empty() && unavailable.top().first <= t) {
                auto it = unavailable.top();
                available.push({mp[it.second], it.second});
                unavailable.pop();
            }
            if (!available.empty()) {
                auto it = available.top();
                res.push_back(it.second);
                available.pop();
                long long k = t + time;
                unavailable.push({k, it.second});
            } else {
                t = unavailable.top().first;
                while (!unavailable.empty() && unavailable.top().first <= t) {
                    auto it = unavailable.top();
                    available.push({mp[it.second], it.second});
                    unavailable.pop();
                }
                if (!available.empty()) {
                    auto it = available.top();
                    res.push_back(it.second);
                    available.pop();
                    long long k = t + time;
                    unavailable.push({k, it.second});
                }
            }
        }
        return res;
    }
};
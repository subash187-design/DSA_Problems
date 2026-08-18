class Solution {
public:
    vector<string> res;
    void bfs(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        queue<tuple<string>> que;
        for (auto i : queries) {
            que.push({i});
        }
        while (!que.empty()) {
            auto [curr] = que.front();
            que.pop();
            for (int j = 0; j < dictionary.size(); j++) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (dictionary[j][i] != curr[i]) {
                        cnt++;
                    }
                }
                if (cnt <= 2){
                    res.push_back(curr);
                    break;
                }
            }
        }
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        bfs(queries, dictionary);
        return res;
    }
};
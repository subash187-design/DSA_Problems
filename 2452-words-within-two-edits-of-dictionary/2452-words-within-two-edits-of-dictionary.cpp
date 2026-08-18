class Solution {
public:
    vector<string> res;
    unordered_map<string, int> mp;
    unordered_set<string>vis;
    void bfs(vector<string>& queries, vector<string>& dictionary) {
        for (auto i : dictionary) {
            mp[i]++;
        }
        int n = queries[0].size();
        queue<tuple<string, int,string>> que;
        for (auto i : queries) {
            que.push({i, 0,i});
        }
        while (!que.empty()) {
            auto [curr,dist,par]=que.front();
            que.pop();
            if (mp[curr] > 0) {
                res.push_back(par);
                continue;
            }
            else if (dist + 1 <= 2) {
                for (int j = 0; j < dictionary.size(); j++) {
                    string orig=curr;
                    for (int i = 0; i < n; i++) {
                        if (dictionary[j][i] != orig[i] ) {
                            orig[i] = dictionary[j][i];
                            string key=par+"#"+orig;
                            if(vis.count(key)==0){
                            vis.insert(key);
                            que.push({orig, dist + 1,par});
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        bfs(queries, dictionary);
        unordered_map<string,int>pre;
        for(auto i:res)
        pre[i]++;
        vector<string>ans;
        for(string i:queries){
            if(pre[i]!=0)
            ans.push_back(i);
        }
        return ans;
    }
};
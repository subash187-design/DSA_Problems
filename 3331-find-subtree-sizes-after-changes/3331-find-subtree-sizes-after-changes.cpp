class Solution {
public:
    vector<int>res;
    int dfs1(int node,vector<vector<int>>&adj){
        int cnt = 1;
        for(int child : adj[node]){
            cnt += dfs1(child,adj);
        }
        res[node] = cnt;
        return cnt;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<int>& parent, string& s,
             vector<int>& vis) {
        if (vis[s[node] - 'a'] != -1) {
            parent[node] = vis[s[node] - 'a'];
        }
        int temp = vis[s[node] - 'a'];
        vis[s[node] - 'a'] = node;
        for (int i : adj[node]) {
            dfs(i, adj, parent, s, vis);
        }
        vis[s[node] - 'a'] = temp;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        res.resize(n,0);
        vector<int> vis(26, -1);
        dfs(0, adj, parent, s, vis);
        adj.clear();
        adj.resize(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        // for(int i = 0; i < n ;i++){
        //     cout<<i<<" : ";
        //     for(int j : adj[i])
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        dfs1(0,adj);
        return res;
    }
};
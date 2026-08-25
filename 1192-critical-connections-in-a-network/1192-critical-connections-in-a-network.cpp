class Solution {
public:
    vector<int> node;
    vector<int> lower;
    vector<vector<int>> res;
    int time = 1;
    void dfs(int i, int par, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;
        node[i] = time;
        lower[i] = time;
        time++;
        for (int nd : adj[i]) {
            if (!vis[nd]) {
                dfs(nd, i, adj, vis);
                lower[i]=min(lower[nd],lower[i]);
                if(lower[nd]>node[i])
                res.push_back({i, nd});

            }
            else if (nd != par) {
                lower[i] = min(lower[nd], lower[i]);
            }
            
        }
    }
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        node.resize(n);
        lower.resize(n);
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1, adj, vis);
        return res;
    }
};
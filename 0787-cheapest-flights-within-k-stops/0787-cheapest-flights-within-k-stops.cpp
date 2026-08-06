class Solution {
public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src, int dst,
                 int k) {

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        set<pair<int, pair<int, int>>> st;


        dist[src][k + 1] = 0;
        st.insert({0, {src, k + 1}});

        while (!st.empty()) {

            auto it = *st.begin();
            st.erase(st.begin());

            int dis = it.first;
            int node = it.second.first;
            int rem = it.second.second;

            if (node == dst)
                return dis;

            if (dis > dist[node][rem])
                continue;

            for (auto& i : adj[node]) {

                int nod = i.first;
                int wt = i.second;

                if (rem > 0 && dis + wt < dist[nod][rem - 1]) {

                    dist[nod][rem - 1] = dis + wt;

                    st.insert({dist[nod][rem - 1], {nod, rem - 1}});
                }
            }
        }

        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& i : flights)
            adj[i[0]].push_back({i[1], i[2]});

        return dijkstra(n, adj, src, dst, k);
    }
};
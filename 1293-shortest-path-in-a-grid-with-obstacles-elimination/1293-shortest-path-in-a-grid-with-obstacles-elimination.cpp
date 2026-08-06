class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1) return 0;
        
        int res=INT_MAX;
        queue<pair<pair<pair<int, int>, int>,int>> que;
        vector<vector<int>> dist(n, vector<int>(m, INT_MIN));
        if (grid[0][0] == 1) {
            que.push({{{0, 0}, k - 1},0});
            dist[0][0] = k - 1;
        } else {
            que.push({{{0, 0}, k},0});
            dist[0][0] = k;
        }
        while (!que.empty()) {
            int a = que.front().first.first.first;
            int b = que.front().first.first.second;
            int l = que.front().first.second;
            int p=que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int x = a + dx[i];
                int y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int s = l;
                    if (grid[x][y] == 1)
                        s = s - 1;
                    if(s<0) continue;
                    else if (s > dist[x][y]) {
                        dist[x][y] = s;
                        if(x==n-1 && y==m-1)
                        res=min(res,p+1);
                        que.push({{{x, y}, s},p+1});
                    }
                }
            }
        }
        return dist[n - 1][m - 1] == INT_MIN ? -1 : res;
    }
};
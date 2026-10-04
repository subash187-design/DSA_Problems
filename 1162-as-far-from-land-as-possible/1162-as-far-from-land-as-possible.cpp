class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        queue<tuple<int,int,int>>que;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        int cnt = 0;
        for(int i = 0 ;i < n; i++){
            for(int j = 0;j < m ; j++){
                 if(grid[i][j] == 1){
                    que.push({i,j,0});
                    dist[i][j]=0;
                 }
            }
        }
        while(!que.empty()){
            auto [i,j,prev] = que.front();
            que.pop();
            ans = max(ans,prev);
            for(int k = 0; k < 4; k++){
                int x = dx[k] + i;
                int y = dy[k] + j;
                if(x >= 0 && x < n && y >= 0 && y < m){
                    int curr = abs(x-i) + abs(y-j) + prev;
                    if(curr < dist[x][y]){
                        dist[x][y] = curr;
                        que.push({x,y,curr});
                    }
                }
            }
        }
        if(ans == 0)
        return -1;
        return ans;
    }
};
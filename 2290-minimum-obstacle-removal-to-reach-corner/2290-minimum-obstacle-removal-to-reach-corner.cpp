class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int bfs(int n,int m,vector<vector<int>>& grid){
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>que;
        que.push({0,{0,0}});
        dist[0][0]=0;
        while(!que.empty()){
            int w=que.top().first;
            int i=que.top().second.first;
            int j=que.top().second.second;
            que.pop();
            if(dist[i][j]<w) continue;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m ){
                    if(w+grid[x][y]<dist[x][y]){
                    dist[x][y]=w+grid[x][y];
                    que.push({w+grid[x][y],{x,y}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      return bfs(n,m,grid);  
    }
};
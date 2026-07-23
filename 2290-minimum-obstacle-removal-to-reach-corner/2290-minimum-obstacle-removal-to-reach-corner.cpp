class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int bfs(int n,int m,vector<vector<int>>& grid){
        vector<vector<int>>vis(n,vector<int>(m,0));
        deque<pair<int,pair<int,int>>>que;
        que.push_front({0,{0,0}});
        vis[0][0]=1;
        while(!que.empty()){
            int w=que.front().first;
            int i=que.front().second.first;
            int j=que.front().second.second;
            que.pop_front();
            if(i==n-1 && j==m-1){
                return w;
            }
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                    vis[x][y]=1;
                    if(grid[x][y]==1){
                        que.push_back({w+1,{x,y}});
                    }
                    else{
                        que.push_front({w,{x,y}});
                    }
                }
            }
        }
        return 0;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      return bfs(n,m,grid);  
    }
};
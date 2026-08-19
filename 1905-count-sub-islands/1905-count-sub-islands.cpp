class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int n,m;
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0 && x<n && y>=0 && y<m){
                if(grid[x][y]==1 && !vis[x][y])
                {
                    dfs(x,y,grid,vis);
                }
            }
        }
    }
    bool check(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<vector<int>>&visit){
        if(vis[i][j]==0)
        return false;
        visit[i][j]=1;
        bool flag=true;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0 && x<n && y>=0 && y<m){
                if(grid[x][y]==1 && !visit[x][y]){
                    if(!check(x,y,grid,vis,visit)){
                        flag=false;
                    }
               }
            }
        }
        if(flag)
        return true;
        return false;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
       n=grid1.size();
       m=grid1[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid1[i][j]==1 && !vis[i][j]){
            dfs(i,j,grid1,vis);
            }
        }
       } 
       int res=0;
       vector<vector<int>>visit(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid2[i][j]==1 && !visit[i][j]){
                if(check(i,j,grid2,vis,visit))
                res++;
            }
        }
       }
       return res;
    }
};
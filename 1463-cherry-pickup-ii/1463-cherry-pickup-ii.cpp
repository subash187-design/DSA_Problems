class Solution {
public:
    int dp[70][70][70][70];
    int n,m;
    int rec(int i,int j,int x,int y,vector<vector<int>>&grid){
        if(i<0 || i>=n || j<0 || j>=m || x<0 || x>=n || y<0 || y>=m){
            return 0;
        }
        if(i==n-1 && x==n-1){
            if(i==x && j==y)
            return grid[x][y];
            return grid[i][j]+grid[x][y];
        }

        if(dp[i][j][x][y]!=-1)
        return dp[i][j][x][y];

        int ans=0;
        if(i==x && j==y)
        ans=grid[i][j];
        else
        ans=grid[i][j]+grid[x][y];
        int res=0;
        res=max(res,rec(i+1,j-1,x+1,y-1,grid));
        res=max(res,rec(i+1,j,x+1,y,grid));
        res=max(res,rec(i+1,j+1,x+1,y+1,grid));
        res=max(res,rec(i+1,j-1,x+1,y,grid));
        res=max(res,rec(i+1,j-1,x+1,y+1,grid));
        res=max(res,rec(i+1,j,x+1,y-1,grid));
        res=max(res,rec(i+1,j,x+1,y+1,grid));
        res=max(res,rec(i+1,j+1,x+1,y-1,grid));
        res=max(res,rec(i+1,j+1,x+1,y,grid));

        return dp[i][j][x][y]=res+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
    n=grid.size();
    m=grid[0].size();
    memset(dp,-1,sizeof(dp));
    return rec(0,0,0,m-1,grid);  
    }
};
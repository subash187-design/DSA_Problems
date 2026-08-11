class Solution {
public:
    int dp[52][52][52];
    int n;
    int rec(int i,int j,int x,int y,vector<vector<int>>&grid){ 
        if(i>=n || j>=n || x>=n || y>=n)
        return INT_MIN;
        if(i==n-1 && j==n-1 && x==n-1 && y==n-1 )
        return grid[i][j];
        if(dp[i][j][x]!=-1)
        return dp[i][j][x];
        if(grid[i][j]==-1 || grid[x][y]==-1)
        return INT_MIN;
        int ans=0;
        if( i==x && j==y){
        ans=grid[i][j];
        }
        else
        ans=grid[i][j]+grid[x][y];
        
        int k=INT_MIN;
        k=max(k,rec(i+1,j,x+1,y,grid));
        k=max(k,rec(i,j+1,x,y+1,grid));
        k=max(k,rec(i,j+1,x+1,y,grid));
        k=max(k,rec(i+1,j,x,y+1,grid));
        return dp[i][j][x]=k+ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {
     n=grid.size();
     memset(dp,-1,sizeof(dp));
     int ans=rec(0,0,0,0,grid);
     return ans<0?0:ans;  
    }
};
class Solution {
public:
    int dp[504][504][3];
    int mod = 1e9 + 7;
    int n,m;
    int rec(int i,int j,int prev,vector<vector<int>>& grid){
        if(i >= n || j >= m)
        return 0;
        if(i == n - 1 && j == m - 1)
        return 1;
        //cout<<i<<" "<<j<<" "<<prev<<endl;
        if(dp[i][j][prev] != -1)
        return dp[i][j][prev];
        int ans = 0;
        if(grid[i][j] == 1){
            if(prev == 1){
                ans = (ans + rec(i , j + 1 , 2, grid));
            }
            else{
                ans = (ans + rec(i + 1, j, 1, grid));
            }
        }
        else{
            ans = (ans + rec(i + 1, j, 1, grid)) % mod;
            ans = (ans + rec(i, j + 1, 2, grid)) % mod;
        }
        return dp[i][j][prev] = ans;


    }
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,grid);
    }
};
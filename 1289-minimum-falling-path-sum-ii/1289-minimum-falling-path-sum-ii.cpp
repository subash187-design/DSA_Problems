class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int rec(int i,int j,vector<vector<int>>& grid){
        if( i == n-1)
        return grid[i][j];
        if(dp[i][j] != -1e7)
        return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0;k < m; k++){
            if(j == k) continue;
            ans = min(ans,rec(i+1,k,grid));
        }
        return dp[i][j] = ans + grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        dp.resize(n,vector<int>(m,-1e7));
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            ans = min(ans, rec(0,i,grid));
        }
        return ans;
    }
};
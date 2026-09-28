class Solution {
public:
    int dp[57][57];
    int n,m;
    int rec(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        if(i == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1)
        return dp[i][j];
        int ans = INT_MAX;
        int value = grid[i][j];
        for(int k = 0;k < m; k++){
            ans = min(ans,moveCost[value][k] + rec(i+1,k,grid,moveCost));
        }
        return dp[i][j] = ans + value;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        memset(dp,-1,sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        int ans = INT_MAX;
        for(int i = 0;i < m;i++){
            ans = min(ans,rec(0,i,grid,moveCost));
        }
        return ans;
    }
};
class Solution {
public:
    int dp[404][404];
    int res=0;
    int rec(int i, int j, vector<vector<int>>& matrix) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        ans = min(ans, rec(i - 1, j, matrix));
        ans = min(ans, rec(i - 1, j - 1, matrix));
        ans = min(ans, rec(i, j - 1, matrix));
        if(matrix[i][j]==1) {
        matrix[i][j]=1+ans;
        res=res+(1+ans);
        return dp[i][j]=1+ans;
        }
        return dp[i][j]=0;
        
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        rec(n - 1, m - 1, matrix);
        return res;

    }
};
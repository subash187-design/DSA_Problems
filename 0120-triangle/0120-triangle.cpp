class Solution {
public:
   vector<vector<int>>dp;
    int rec(int i,int j,vector<vector<int>>& triangle){
        if(i>=triangle.size()) return 0;
        if(dp[i][j]!=1e9) return dp[i][j];
        int ans=0;
        ans=triangle[i][j]+min(rec(i+1,j,triangle),rec(i+1,j+1,triangle));
        return dp[i][j]=ans;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        dp.resize(n,vector<int>(m,1e9));
        return rec(0,0,triangle);
    }
};
class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int rec(int i,int j,vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=n || j>=n) return 1e7;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int ans=1e7;
        ans=min(ans,matrix[i][j]+rec(i+1,j,matrix));
        ans=min(ans,matrix[i][j]+rec(i+1,j+1,matrix));
        ans=min(ans,matrix[i][j]+rec(i+1,j-1,matrix));
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
   
      n=matrix.size();
         dp.resize(n,vector<int>(n,1e9));
      int ans=INT_MAX;
      for(int i=0;i<n;i++){
        ans=min(ans,rec(0,i,matrix));
      } 
      return ans;
    }
};
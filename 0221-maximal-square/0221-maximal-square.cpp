class Solution {
public:
    vector<vector<int>>dp;
    int rec(int i,int j,vector<vector<char>>& matrix){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(matrix[i][j]=='0')
        return dp[i][j]=0;
        return dp[i][j]=min({rec(i-1,j,matrix),
        rec(i,j-1,matrix),
        rec(i-1,j-1,matrix)})+1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int k=rec(i,j,matrix);
                res=max(res,k*k);
            }
        }
        return res;
        

    }
};
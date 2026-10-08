class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
     int n = mat.size();
     int m = mat[0].size();
     vector<vector<int>>prefixSum(n+1,vector<int>(m+1,0));
     vector<vector<int>>res(n,vector<int>(m,0));
     for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            prefixSum[i][j] = mat[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
     } 
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            int top = max(0, i - k);
            int left = max(0, j - k);
            int bottom = min( i + k , n - 1);
            int right = min( j + k , m - 1);
            res[i][j] = prefixSum[bottom + 1][right + 1] - prefixSum[top][right + 1] - prefixSum[bottom + 1][left] + prefixSum[top][left];
        }
     }
     return res;  
    }
};
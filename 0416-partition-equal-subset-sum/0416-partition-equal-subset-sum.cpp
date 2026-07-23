class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sm=accumulate(arr.begin(),arr.end(),0);
        if(sm%2==1) return false;
        int W=sm/2;
        vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(W+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(j<arr[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                }
            }
        }
        return dp[n][W]>=2;
    }
};
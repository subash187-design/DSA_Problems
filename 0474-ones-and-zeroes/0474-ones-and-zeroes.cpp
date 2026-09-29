class Solution {
public:
    int dp[604][104][104];
    int rec(int i,int m,int n,vector<string>&strs){
        if(i >= strs.size())
        return 0;
        if(m < 0 && n < 0)
        return 0;
        if(dp[i][m][n] != -1)
        return dp[i][m][n];
        int ans = 0;
        int cm = m;
        int cn = n;
        for(int j = 0; j < strs[i].size();j++){
            if(strs[i][j] == '0')
            cm--;
            else
            cn--;
        }
        if(cm >= 0 && cn >= 0){
            ans = max(ans,1 + rec(i+1,cm,cn,strs));
        }
        ans = max(ans,rec(i+1,m,n,strs));
        return dp[i][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,m,n,strs);
    }
};
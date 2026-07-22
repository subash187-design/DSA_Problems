class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      vector<vector<int>>dp(n,vector<int>(n,0));
      int cnt=0;
      for(int diff=0;diff<n;diff++){
       for(int i=0,j=i+diff;j<n;i++,j++){
        if(i==j) dp[i][j]=1;
        else if(j-i==1){
            if(s[i]==s[j]) dp[i][j]=2;
            else dp[i][j]=0;
        }
        else{
            if(s[i]==s[j] && dp[i+1][j-1]!=0){
                dp[i][j]=2+dp[i+1][j-1];
            }
        }
        if(dp[i][j]!=0)
        cnt++;
       }
      }
      return cnt;
    }
};
class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      vector<vector<int>>dp(n,vector<int>(n,0));
      int cnt=0;
      for(int i=0;i<n;i++){
       int x=0;
       int y=i;
       while(x<n && y<n){
        if(x==y) dp[x][y]=1;
        else if(y-x==1) {
            if(s[x]==s[y]) dp[x][y]=2;
            else dp[x][y]=0;
        }
        else  {
            if(s[x]==s[y] && dp[x+1][y-1]!=0)
            dp[x][y]=2+dp[x+1][y-1];
        }
        if(dp[x][y]!=0) cnt++;
        x++;
        y++;
       }
      }
      return cnt;
    }
};
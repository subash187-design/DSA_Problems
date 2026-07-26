class Solution {
public:
    int dp[24][24];
    int n,m;
    int rec(int i,int j,string &s,string &p){
        if(i==n && j==m) return 1;
        if(i>n || j>m ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==p[j] || p[j]=='.')
        ans=ans || rec(i+1,j+1,s,p);
        if(j+1<m && p[j+1]=='*'){
            if(s[i]==p[j] || p[j]=='.'){
                ans=ans || rec(i+1,j,s,p);
            }
              ans=ans || rec(i,j+2,s,p);
        }
        cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s,p);
    }
};
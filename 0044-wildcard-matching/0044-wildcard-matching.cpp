class Solution {
public:
    int dp[2005][2005];
    int n,m;
    int rec(int i,int j,string& s,string& p){
        if(i<0 && j<0) return 1;
        if(i<0 && j>=0){
            for(int k=j;k>=0;k--){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')
        return dp[i][j]=rec(i-1,j-1,s,p);
        else if(p[j]=='*')
        return dp[i][j]=rec(i-1,j,s,p) || rec(i,j-1,s,p);
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
     n=s.size();
     m=p.size();
     memset(dp,-1,sizeof(dp));
     return rec(n-1,m-1,s,p);   
    }
};
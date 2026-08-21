class Solution {
public:
    int dp[22][22];
    int rec(int i,int j,string& s,string& p){
        if(i<0){
            for(int k=j;j>=0;j-=2){
            if(p[j]!='*') return 0;
            }
            return 1;
        }
        if(j<0) 
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans = 0;
        if(s[i]==p[j] || p[j]=='.')
        ans = ans || rec(i-1,j-1,s,p);
        if(p[j]=='*'){
        if(j-1>=0 && s[i]==p[j-1] || p[j-1]=='.')
        ans = ans || rec(i-1,j,s,p) || rec(i-1,j-2,s,p);
        ans = ans || rec(i,j-2,s,p);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int m=p.size();
        return  rec(n-1,m-1,s,p);
    }
};
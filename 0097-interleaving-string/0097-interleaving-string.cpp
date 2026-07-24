class Solution {
public: 
    int dp[202][202][202];
    bool rec(int i,int j,int k,string s1,string s2,string s3){
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(k<0 && i<0 && j<0) return true;
        if(k<0 && (i>=0 || j>=0)) return false;

        if(i<0 && j<0 &&k>=0) return false;
        if(dp[i+100][j+100][k]!=-1) return dp[i+100][j+100][k];
        int ans=0;
        if( i>=0 && j>=0 && s1[i]!=s3[k] && s2[j]!=s3[k])
        return false;
        if( i>=0 && s1[i]==s3[k])
        ans=ans | rec(i-1,j,k-1,s1,s2,s3);
        if( j>=0 && s2[j]==s3[k])
        ans=ans | rec(i,j-1,k-1,s1,s2,s3);
        return dp[i+100][j+100][k]=ans;


    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        int i=s1.size()-1;
        int j=s2.size()-1;
        int k=s3.size()-1;
      return rec(i,j,k,s1,s2,s3);  
    }
};
class Solution {
public:
    vector<vector<int>>dp;
    int lcs(int i,int j,string& text1,string& text2){
        if(i < 0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(text1[i]==text2[j])
        return dp[i][j] = 1+lcs(i-1,j-1,text1,text2);
        return  dp[i][j] = max(lcs(i-1,j,text1,text2),(lcs(i,j-1,text1,text2)));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        dp.resize(m,vector<int>(n,-1));
        return lcs(m-1,n-1,text1,text2);
    }
};
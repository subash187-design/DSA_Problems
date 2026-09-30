class Solution {
public:
    int dp[102][102];
    bool rec(int i,int op,string& s){
        if(i >= s.size())
        return op == 0;
        if(op < 0)
        return 0;
        if(dp[i][op] != -1)
        return dp[i][op];
        bool ans = false;
        if(s[i] == '(')
        ans |= rec(i+1,op+1,s);
        else if(s[i] == ')')
        ans |= rec(i+1,op-1,s);
        else{
        ans |= rec(i+1,op+1,s);
        ans |= rec(i+1,op-1,s);
        ans |= rec(i+1,op,s);
        }
        return dp[i][op] = ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s);
    }
};
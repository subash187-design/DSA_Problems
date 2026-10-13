class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int gcdd(int a,int b){
        if(b == 0)
        return a;
        return gcdd(b,a%b);
    }
    int rec(int n,int prev1,int prev2){
        if(n == 0)
        return 1;
        if(dp[n][prev1 + 1][prev2 + 1] != -1){
            return dp[n][prev1 + 1][prev2 + 1];
        }
        int ans = 0;
        // cout<<n<<" "<<prev1<<" "<<prev2<<endl;
        for(int i = 1; i <= 6;i++){
            if(prev1 == -1 || (prev1 != i && prev2 == -1) || (prev1 != i && prev2 != i)){
                if(prev1 == -1 || gcdd(prev1,i) == 1)
                ans = (ans +  rec(n-1,i,prev1)) % mod;
            }
              
        }
        return dp[n][prev1 + 1][prev2 + 1] = ans;
    }
    int distinctSequences(int n) {
      dp.resize(n+1,vector<vector<int>>(8,vector<int>(8,-1)));
      return rec(n,-1,-1);  
    }
};
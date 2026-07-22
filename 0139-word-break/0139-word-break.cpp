class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int k=0;
        for (string w:wordDict) {
            st.insert(w);
            int a=w.size();
            k=max(k,a);
        }
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1; 
        for(int i=n-1;i>=0;i--) {
            for (int j=i;j<min(n,i+k);j++) {
                string x=s.substr(i,j-i+1);
                if (st.find(x)!=st.end() && dp[j+1]) {
                    dp[i]=1;
                    break;
                }
            }
        }

        return dp[0];
    }
};
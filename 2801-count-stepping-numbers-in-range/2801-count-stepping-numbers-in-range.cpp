class Solution {
public:
    int dp[101][2][2][15];
    int mod = 1e9 + 7;
    int rec(int pos,int isStart,int tight,int prev,string num){
        //cout<<pos<<" "<<isStart<<" "<<tight<<" "<<prev<<" "<<num<<endl;
        if(pos >= num.size()){
            return isStart;
        }
        if(dp[pos][isStart][tight][prev+1] != -1)
        return dp[pos][isStart][tight][prev+1];
        int ans = 0;
        int bound = (tight == 1) ? num[pos] - '0' : 9;
        //cout<<pos<<" "<<isStart<<" "<<tight<<" "<<prev<<" "<<num<<" "<<bound<<endl;
        for(int i = 0 ; i <= bound ; i++ ){
            int newTight = (tight == 1 && i == (num[pos] - '0')) ? 1 : 0;
            int newStart = (isStart || i != 0) ? 1 : 0;
            // cout<<i <<" "<<newStart<<" "<<newTight<<endl;
            if(!newStart){
                ans = (ans + rec(pos + 1, 0, newTight, prev, num)) % mod;
            }
            else if(prev == -1 || abs(prev - i ) == 1 ){
                ans = (ans + rec(pos + 1, newStart, newTight, i, num)) % mod;
            }
        }
        return dp[pos][isStart][tight][prev+1] = ans;
    }
    int countSteppingNumbers(string low, string high) {
       memset(dp,-1,sizeof(dp));
       int ans1 = rec(0,0,1,-1,low);
       memset(dp,-1,sizeof(dp)); 
       int ans2 = rec(0,0,1,-1,high);
       bool flag = true;
       for(int i = 1; i < low.size();i++){
        int a = low[i] - '0';
        int b = low[i - 1] - '0';
        if(abs(a-b) != 1)
        {
            flag = false;
            break;
        }
       }
       if(flag)
       ans1 = (ans1 - 1) % mod;
       //cout<<ans1<<" "<<ans2<<endl;
       return (ans2 - ans1 + mod) % mod;
    }
};
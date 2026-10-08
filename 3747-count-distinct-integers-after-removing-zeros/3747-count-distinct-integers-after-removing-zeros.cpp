#define ll long long
class Solution {
public:
    ll dp[17][2][2];
    ll rec(int pos,int isStart,int tight,vector<int>& arr){
        if(pos >= arr.size())
        return isStart;
        if(dp[pos][isStart][tight] != -1)
        return dp[pos][isStart][tight];
        ll ans = 0;
        int bound = (tight == 1) ? arr[pos] : 9;
        for(int i = 0; i <= bound ; i++){
            int newStart = (isStart || i != 0) ? 1 : 0;
            int newTight = (tight && i == arr[pos]) ? 1 : 0;
            if(!newStart){
                ans += rec(pos + 1, newStart, newTight, arr);
            }
            else if(i != 0){
                ans += rec(pos + 1, newStart, newTight, arr);
            }
        }
        return dp[pos][isStart][tight] = ans;
    }
    long long countDistinct(long long n) {
        memset(dp,-1,sizeof(dp));
        vector<int>arr;
        while(n){
            arr.push_back(n % 10);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        return rec(0,0,1,arr);
    }
};
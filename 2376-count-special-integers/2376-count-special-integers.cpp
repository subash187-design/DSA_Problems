class Solution {
public:
    int dp[10][2][2][4096];
    int rec(int pos,int tight,int isStart,int mask,vector<int>&arr){
        if(pos >= arr.size())
        return mask != 0;
        if(dp[pos][tight][isStart][mask] != -1)
        return dp[pos][tight][isStart][mask];
        int ans = 0;
        int bound = (tight == 1) ? arr[pos] : 9;
        for(int i = 0; i <= bound ; i++){
            int newStart = (isStart == 1 || i != 0) ? 1 : 0;
            int newTight = (i == bound && tight == 1) ? 1 : 0;
            if(newStart == 0){
                ans += rec(pos + 1, newTight, newStart, mask, arr);
            }
            else if(!((mask >> i) & 1)){
                int newMask = mask | (1 << i);
                ans += rec(pos + 1, newTight, newStart, newMask, arr);
            }
        }

        return dp[pos][tight][isStart][mask] = ans;
    }
    int countSpecialNumbers(int num) {
        vector<int>arr;
        while(num){
            int k = num % 10;
            arr.push_back(k);
            num = num / 10;
        }
        memset(dp,-1,sizeof(dp));
        reverse(arr.begin(),arr.end());
        return rec(0,1,0,0,arr);
    }
};
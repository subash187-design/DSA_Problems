#define ll long long
class Solution {
public:
    ll dp[17][2][2][12];
    ll rec(int i,int isStart,int tight,int prev,int k,vector<int>&arr){
        if(i >= arr.size())
        return 1;
        if(dp[i][isStart][tight][prev + 1] != -1)
        return dp[i][isStart][tight][prev + 1];
        ll ans = 0;
        int bound = (tight == 1) ? arr[i] : 9;
        for(int j = 0; j <= bound; j++){
            int newStart = (isStart || j != 0) ? 1 : 0;
            int newTight = (tight && j == arr[i]) ? 1 : 0;
            if(j == 0 && prev == -1){
               ans += rec(i + 1, newStart, newTight, -1 ,k, arr); 
            }
            else if(prev == -1 || abs(prev - j) <= k){
                ans += rec(i + 1, newStart, newTight, j, k, arr);
            }
        }
        return dp[i][isStart][tight][prev + 1] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        l = l - 1;
        vector<int>arr1,arr2;
        while(l){
            arr1.push_back(l % 10);
            l /= 10;
        }
        while(r){
            arr2.push_back(r % 10);
            r /= 10;
        }
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        memset(dp,-1,sizeof(dp));
        ll ans1 = rec(0,0,1,-1,k,arr2);
        memset(dp,-1,sizeof(dp));
        ll ans2 = rec(0,0,1,-1,k,arr1);
        cout<<ans1<<" "<<ans2<<endl;
        return ans1 - ans2;
    }
};
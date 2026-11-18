class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int mod = 1e9 + 7;
    int rec(int i,int sum,vector<int>& arr){
        if(i >= n)
        return 0;
        if(dp[i][sum + 1] != -1){
            return dp[i][sum + 1];
        }
        int cnt = 0;
        
        if(sum == -1){
            int x = arr[i] & 1;
            cnt = (cnt + (x + rec(i + 1, arr[i] & 1,arr))) % mod;
            cnt = (cnt + rec(i + 1, -1, arr)) % mod;
        }
        else{
            
            int curr = arr[i] + sum;
            int x = curr & 1;
            cnt = (x + rec(i + 1, x, arr)) % mod;
            
           
        }
        return dp[i][sum + 1] = cnt;
    }
    int numOfSubarrays(vector<int>& arr) {
       n = arr.size();
       dp.resize(n,vector<int>(3,-1)); 
       return rec(0,-1,arr);
    }
};
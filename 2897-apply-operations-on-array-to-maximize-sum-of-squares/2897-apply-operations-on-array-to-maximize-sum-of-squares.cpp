class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
      vector<int>freq(30,0);
      for(int num : nums){
        for(int i = 0 ;i < 30; i++){
            if((num >> i) & 1){
                freq[i]++;
            }
        }
      }  
      long long res = 0;
      while(k--){
        int curr = 0;
        for(int i = 0; i < 30; i++){
            if(freq[i] > 0){
                curr = (curr | (1 << i));
                freq[i]--;
            }
        }
        res = (res +  ((1ll * curr * curr) % mod)) % mod;
      }
      return res;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int curr = -1;
        for(int i = 0;i < n; i++){
            if(curr == -1){
                curr = prices[i];
            }
            else if(curr <= prices[i]){
                res = max(res, prices[i] - curr);
            }
            else if(curr > prices[i]){
                curr = prices[i];
            }
        }
        return res;
    }
};
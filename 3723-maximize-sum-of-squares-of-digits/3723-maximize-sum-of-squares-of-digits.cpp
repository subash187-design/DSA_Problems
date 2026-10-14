class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while(num--){
            int k = 9;
            if(k <= sum){
                res += (9 + '0');
                sum -= 9;
            }
            else{
                res += (sum + '0');
                sum -= sum;
            }
        }
        if(sum > 0)
        return "";
        return res;
    }
};
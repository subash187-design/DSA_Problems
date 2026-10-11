class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        for(int i=1;i<=nums.size();i++){
            int a=nums[i-1];
            if(n%i==0){
                res+=(long long)a*a;
            }
        }
        return int(res);
    }
};
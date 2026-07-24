class Solution {
public:
    bool check(int m,vector<int>& weights, int days){
        int sum=0;
        int cnt=1;
        for(int i:weights){
            sum+=i;
            if(sum>m){
                cnt++;
                sum=i;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
      int l=*max_element(weights.begin(),weights.end());
      int r=accumulate(weights.begin(),weights.end(),0);
      int ans=0;
      while(l<=r){
        int m=l+(r-l)/2;
        if(check(m,weights,days)){
            ans=m;
            r=m-1;
        }
        else
        l=m+1;
      }  
      return ans;
    }
};
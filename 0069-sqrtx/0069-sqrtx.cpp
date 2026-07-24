class Solution {
public:
    int mySqrt(int x) {
       int l=0;
       int r=x;
       int ans=0;
       while(l<=r){
        long long m=l+(r-l)/2;
        if(m*m<=x){
            ans=m;
            l=m+1;
        } 
        else r=m-1;
       } 
       return ans;
    }
};
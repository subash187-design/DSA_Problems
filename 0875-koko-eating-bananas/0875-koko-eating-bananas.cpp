class Solution {
public:
    bool check(int m,vector<int>& piles, int h){
        long long cnt=0;
        for(int i:piles){
            cnt+=(i+m-1)/m;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int l=1;
       int r=*max_element(piles.begin(),piles.end());
       int ans=0;
       while(l<=r){
        int m=l+(r-l)/2;
        if(check(m,piles,h)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
       }
       return ans;

    }
};
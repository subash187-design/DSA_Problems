
class Solution {
public:
    bool check(vector<int>&arr,int m){
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=m)
            cnt++;
        }
        return cnt>=m;
    }
    int hIndex(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=*max_element(arr.begin(),arr.end());
        int res=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(check(arr,m))
            {
                l=m+1;
                res=m;
            }
            else
            r=m-1;
        }
        return res;
    }
};
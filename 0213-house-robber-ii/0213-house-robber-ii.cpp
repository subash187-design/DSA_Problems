class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==0)
        return 0;
        else if(n==1)
        return arr[0];
        else if(n==2)
        return max(arr[0],arr[1]);
        int dp1[n],dp2[n];
        dp1[0]=arr[0];
        dp1[1]=max(arr[0],arr[1]);
        for(int i=2;i<n-1;i++){
            dp1[i]=max(dp1[i-1],arr[i]+dp1[i-2]);
        }
        dp2[0]=0;
        dp2[1]=arr[1];
        dp2[2]=max(arr[1],arr[2]);
        for(int i=3;i<n;i++){
             dp2[i]=max(dp2[i-1],arr[i]+dp2[i-2]);
        }
    
        return max(dp1[n-2],dp2[n-1]);
    }
};
class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n=arr.size();
      vector<int>pre(n);
      vector<int>suff(n);
      pre[0]=arr[0];
      suff[n-1]=arr[n-1];
      for(int i=1;i<n;i++)
      pre[i]=max(pre[i-1]+arr[i],arr[i]);
      for(int i=n-2;i>=0;i--){
        suff[i]=max(suff[i+1]+arr[i],arr[i]);
      }  

      int res=INT_MIN;
      for(int i:pre)
      res=max(res,i);
      for(int i=1;i<n-1;i++){
        res=max(res,pre[i-1]+suff[i+1]);
      }
      return res;
    }
};
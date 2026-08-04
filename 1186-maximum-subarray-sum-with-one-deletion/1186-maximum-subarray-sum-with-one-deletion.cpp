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
      for(int i=0;i<n;i++){
        if(i==0){
        if(i+1<n)
        res=max({res,arr[i],suff[i+1]});
        else
        res=max(res,arr[i]);
        }
        else if(i==n-1){
        if(i-1>=0)
        res=max(res,arr[i]);
        else
        res=max({res,arr[i],pre[i-1]});
        }
        else
        res=max({res,pre[i-1]+suff[i+1],pre[i],suff[i],pre[i]+suff[i+1]});
      }
      return res;
    }
};
class Solution {
public:
    int largestInteger(int n, int s) {
      if(s==0) return 0;
      int i,j;
      if (n==1) {
        i=1;
        j=9;
      }
      else if(n==2){
        i=10;
        j=99;
      }
      else if(n==3)
      {
        i=100;
        j=999;
      }
      else if(n==4){
        i=1000;
        j=9999;
      }
      else if(n==5){
        i=10000;
        j=99999;
      }
      int res=0;
      for(j;j>=i;j--){
        int temp=j;
        int sum=0;
        while(temp){
            sum+=(temp%10);
            temp=temp/10;
        }
        if(sum==s) return j;
      }
      return -1;
    }
};
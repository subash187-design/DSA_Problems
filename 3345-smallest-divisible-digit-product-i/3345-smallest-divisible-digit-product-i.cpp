class Solution {
public:
    int smallestNumber(int n, int t) {
     int res=n;
     while(true){
        int k=n;
        int prod=1;
        while(k){
            int a=k%10;
            prod*=a;
            k=k/10;
        }
        if(prod%t==0){
            res=n;
            break;
        }
        n++;
     }
     return res;   
    }
};
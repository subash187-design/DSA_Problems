class Solution {
public:
    int dp[32][2][2][4000];
    int rec(int pos,int tight,int isStart,int cnt,vector<int>&arr){
        if(pos==arr.size())
        return cnt;
        if(dp[pos][tight][isStart][cnt]!=-1){
            return dp[pos][tight][isStart][cnt];
        }
        int ans=0;
        int bound=(tight==1)?arr[pos]:9;
        for(int i=0;i<=bound;i++){
            int newStart=(isStart==1 || i!=0)?1:0;
            int newTight=(tight==1 && i==bound)?1:0;
            if(i==1)
            ans+=rec(pos+1,newTight,newStart,cnt+1,arr);
            else
            ans+=rec(pos+1,newTight,newStart,cnt,arr);
        }
       
        return dp[pos][tight][isStart][cnt]=ans;

    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>arr;
        int temp=n;
        while(temp){
            arr.push_back(temp%10);
            temp=temp/10;
        }
        reverse(arr.begin(),arr.end());
        return rec(0,1,0,0,arr);
    }
};
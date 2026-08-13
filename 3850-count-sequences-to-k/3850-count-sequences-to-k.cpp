#define ll unsigned long long
class Solution {
public:
    ll gcdd(ll a,ll b){
        if(b==0)
         return a;
        return gcdd(b,a%b);
    }
    void rec(int i,ll num,ll den,vector<int>&arr,vector<pair<ll,ll>>&frac){
    if(i==arr.size()){
        ll k=gcd(num,den);
        num=num/k;
        den=den/k;
        frac.push_back({num,den});
        return;
    }
    rec(i+1,num,den,arr,frac);
    rec(i+1,num,den*arr[i],arr,frac);
    rec(i+1,num*arr[i],den,arr,frac);
    }
    int countSequences(vector<int>& nums, long long k) {
        vector<vector<int>>arr(2);
        for(int i=0;i<nums.size();i++){
            // checking odd or even for i
            arr[i&1].push_back(nums[i]);
        }
        vector<pair<ll,ll>>frac1,frac2;
        rec(0,1,1,arr[0],frac1);
        rec(0,1,1,arr[1],frac2);
    int cnt=0;
    map<pair<ll,ll>,int>mp;
    for(auto& i:frac1){
        mp[i]++;
    }
    for(auto& i:frac2){
        ll a=i.second*k;
        ll b=i.first;
        ll c=gcd(a,b);
        a=a/c;
        b=b/c;
        cnt+=mp[{a,b}];
    }
    return cnt;
    }
};
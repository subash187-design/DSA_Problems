class Solution {
public:
    void solve(vector<int>&arr,vector<long long>&sett){
        int n=arr.size();
        for(int i=0;i<(1<<n);i++){
            int sm=0;
            for(int pos=0;pos<n;pos++){
                if((i>>pos)&1)
                sm+=arr[pos];
            }
            sett.push_back(sm);
        }
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>arr1,arr2;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                arr1.push_back(nums[i]);
            }
            else
                arr2.push_back(nums[i]);
        }
        vector<long long>set1,set2;
        solve(arr1,set1);
        solve(arr2,set2);
        sort(set2.begin(),set2.end());
        int res=INT_MAX;
        for(long long i:set1){
            auto it=lower_bound(set2.begin(),set2.end(),goal-i);
                if(it==set2.end())
                it=it-1;
                long long a=*it;
                int x=abs((a+i)-(goal));
                if(x>=0)
                res=min(res,x);
                if(it!=set2.begin()){
                   it=it-1; 
                long long a=*it;
                int x=abs((a+i)-(goal));
                if(x>=0)
                res=min(res,x);
                }
        }
        return res;

    }
};
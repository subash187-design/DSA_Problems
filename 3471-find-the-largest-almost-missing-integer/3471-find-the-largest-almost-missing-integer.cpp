class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        int l=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            if(r-l+1>k){
                mp[nums[l]]--;
                l++;
            }
            if(r-l+1==k){
                for(auto i:mp){
                    if(i.second>0)
                    mp1[i.first]++;
                }
            }


        }
        int res=-1;
        for(auto i:mp1){
            if(i.second==1)
            res=max(res,i.first);
        }
        return res;
    }
};
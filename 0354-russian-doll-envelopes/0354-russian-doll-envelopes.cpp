class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       
       vector<pair<int,int>>nums;
       for(int i=0;i<envelopes.size();i++){
        nums.push_back({envelopes[i][0],envelopes[i][1]});
       }
       sort(nums.begin(),nums.end(),[](pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
       });
       vector<int>res;
       for(int i=0;i<nums.size();i++){
        int a=nums[i].second;
        int it=lower_bound(res.begin(),res.end(),a)-res.begin();
        if(it>=res.size()) res.push_back(a);
        else {
            res[it]=a;
        }
       }
        return res.size();
       
    }
};

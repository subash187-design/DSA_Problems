class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int l=0;
       int r=0;
       vector<int>res;
       set<pair<int,int>,greater<pair<int,int>>>st;
       for(r;r<nums.size();r++){
        st.insert({nums[r],r});
        if(r-l+1>k){
            st.erase({nums[l],l});
            l++;
        }
        if(r-l+1==k){
            auto t=*st.begin();
            res.push_back(t.first);
        }
       } 
       return res;
    }
};
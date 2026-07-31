class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       int r=0;
       vector<int>res;
       priority_queue<pair<int,int>>pq;
       for(r;r<nums.size();r++){
        pq.push({nums[r],r});
        while(pq.top().second<=r-k){
            pq.pop();
        }
        if(r+1>=k){
            res.push_back(pq.top().first);
        }
       } 
       return res;
    }
};
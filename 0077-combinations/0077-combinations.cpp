class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>res;
       for(int i=1;i<(1<<n);i++){
        vector<int>curr;
        for(int pos=0;pos<n;pos++){
            if((i>>pos)&1)
            curr.push_back(pos+1);
        }
        if(curr.size()==k)
        res.push_back(curr);
       } 
       return res;
    }
};
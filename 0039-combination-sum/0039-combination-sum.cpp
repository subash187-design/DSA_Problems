class Solution {
public:
    vector<vector<int>>res;
    void rec(int i,int target,vector<int>&candidates,vector<int>&temp){
        if(i==candidates.size()){
            if(target==0){
                res.push_back(temp);
            }
            return;
        }
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            rec(i,target-candidates[i],candidates,temp);
            temp.pop_back();
        }
        rec(i+1,target,candidates,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        rec(0,target,candidates,temp);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>>ans;
    void rec(int i,int target,vector<int>&candidates,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if( j>i && candidates[j]==candidates[j-1]) continue;
            else if(candidates[j]>target) break;
           
            temp.push_back(candidates[j]);
            rec(j+1,target-candidates[j],candidates,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int>temp;
       sort(candidates.begin(),candidates.end());
       rec(0,target,candidates,temp);
       return ans;

    }
};
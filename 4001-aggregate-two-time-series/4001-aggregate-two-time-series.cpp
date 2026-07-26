class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<int>temp1;
        vector<int>temp2;
        for(auto i:series1) temp1.push_back(i[0]);
        for(auto i:series2) temp2.push_back(i[0]);
        vector<vector<int>>res;
        unordered_map<int,int>mp;
        for(int i=0;i<temp1.size();i++){
            if(mp[temp1[i]]==0){
                mp[temp1[i]]=1;
                int a=series1[i][1];
                int b=0;
                auto it=lower_bound(temp2.begin(),temp2.end(),temp1[i]);
                if(it!=temp2.end()) {
                    int j=it-temp2.begin();
                    b=series2[j][1];
                }
                res.push_back({temp1[i],a+b});
            }
        }
        for(int i=0;i<temp2.size();i++){
            if(mp[temp2[i]]==0){
                mp[temp2[i]]=1;
                int a=series2[i][1];
                int b=0;
                auto it=lower_bound(temp1.begin(),temp1.end(),temp2[i]);
                if(it!=temp1.end()) {
                    int j=it-temp1.begin();
                    b=series1[j][1];
                }
                res.push_back({temp2[i],a+b});
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};
class Solution {
public:
    int dp[1004];
    int rec(int i,vector<pair<int,int>>&basket){
        if(i >= basket.size())
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int ans = 0;
        cout<<i<<endl;
        for(int j = i + 1; j < basket.size(); j++){
            if(basket[j].second >= basket[i].second)
            ans = max(ans,rec(j,basket));
        }
        return dp[i] = ans + basket[i].second;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>basket;
        int n = scores.size();
        for(int i = 0; i < n; i++){
            basket.push_back({ages[i],scores[i]});
        }
        sort(basket.begin(),basket.end(),[](auto &a, auto &b){
            if(a.first == b.first)
            return a.second < b.second;
            return a.first < b.first;
        });
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = 0;i < n; i++){
            ans = max(ans,rec(i,basket));
        }
        return ans;
    }
};
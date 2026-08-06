class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
     vector<vector<pair<int,int>>>adj(n);
     for(int i=0;i<red.size();i++){
        int a=red[i][0];
        int b=red[i][1];
        adj[a].push_back({b,1});
     }
     for(int i=0;i<blue.size();i++){
        int a=blue[i][0];
        int b=blue[i][1];
        adj[a].push_back({b,0});
     }  
     queue<pair<int,pair<int,int>>>que;
     vector<int>res(n,-1);
     vector<vector<int>>vis(n,vector<int>(2,0));
     que.push({0,{-1,0}});
     res[0]=0;
     while(!que.empty()){
        int node=que.front().first;
        int col=que.front().second.first;
        int dis=que.front().second.second;
        que.pop();
        for(auto k:adj[node]){
            int a=k.first;
            int b=k.second;
            if(b!=col && !vis[a][b]){
                vis[a][b]=1;
                if(res[a]==-1)
                res[a]=dis+1;
                que.push({a,{b,dis+1}});
            }

        }
     } 
     return res; 
    }
};
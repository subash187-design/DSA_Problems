class Solution {
public:
    void bfs(int i,int n,vector<vector<int>>&adj,vector<int>&vis){
       queue<int>que;
       que.push({i});
       vis[i]=1;
       while(!que.empty()){
        int a=que.front();
        que.pop();
        for(int i:adj[a]){
            if(vis[i]==0)
            {
                vis[i]=1;
                que.push(i);
            }
        }
       }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       int k=connections.size();
       if((n-1)>k)
       return -1;
       vector<vector<int>>adj(n);
       vector<int>vis(n,0);
       for(int i=0;i<connections.size();i++){
        int a=connections[i][0];
        int b=connections[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
       }
       int cnt=0;
       for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,n,adj,vis);
            cnt++;
        }
       }
       
       return cnt-1;
    }
};
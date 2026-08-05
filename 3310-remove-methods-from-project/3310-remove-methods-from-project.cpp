class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        vector<int>res;
        for(int i=0;i<invocations.size();i++){
            int a=invocations[i][0];
            int b=invocations[i][1];
            adj[a].push_back(b);
            indeg[b]++;
        }
        queue<int>que;
        vector<int>susp(n,0);
        vector<int>vis(n,0);
        susp[k]=1;
        que.push(k);
        vis[k]=1;
        while(!que.empty()){
            int node=que.front();
            que.pop();
            for(int i:adj[node]){
                indeg[i]--;
                susp[i]=1;
                if(vis[i]==0){
                vis[i]=1;
                que.push(i);
                }
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++){
            if(susp[i]==0)
            res.push_back(i);
            else if(susp[i]==1 && indeg[i]>0){
                flag=true;
                break;
            }
        }
        if(flag){
            res.clear();
            for(int i=0;i<n;i++)
            res.push_back(i);
        }
        return res;
    }
};
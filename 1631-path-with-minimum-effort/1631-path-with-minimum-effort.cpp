class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int n,m;
    bool bfs(vector<vector<int>>& heights,int k){
      vector<vector<int>>vis(n,vector<int>(m,0));
      queue<pair<int,int>>que;
      que.push({0,0});
      vis[0][0]=1;
      while(!que.empty()){
        int a=que.front().first;
        int b=que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int x=dx[i]+a;
            int y=dy[i]+b;
            if(x>=0 && x<n && y>=0 && y<m){
                int fir=heights[a][b];
                int sec=heights[x][y];
                int diff=abs(fir-sec);
                if(!vis[x][y] && diff<=k){
                    if(x==n-1 && y==m-1)
                    return true;
                    vis[x][y]=1;
                    que.push({x,y});
                }

            }
        }
      }
      return false; 
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
       n=heights.size();
       m=heights[0].size();
       
       int res=0;
       int l=0;
       int r=INT_MIN;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            r=max(heights[i][j],r);
        }
       }
       while(l<=r){
        int m=l+(r-l)/2;
        if(bfs(heights,m)){
            cout<<m<<endl;
            r=m-1;
            res=m;
        }
        else
        l=m+1;
       }
       return res;
    }
};
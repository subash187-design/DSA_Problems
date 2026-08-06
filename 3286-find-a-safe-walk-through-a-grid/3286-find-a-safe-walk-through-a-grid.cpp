class Solution {
public:
    int n,m;
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    bool dijkstra(vector<vector<int>>& grid,int health){
        set<pair<int,pair<int,int>>,greater<pair<int,pair<int,int>>>>st;
        vector<vector<int>>dist(n,vector<int>(m,INT_MIN));
        if(grid[0][0]==1)
        st.insert({health-1,{0,0}});
        else
        st.insert({health,{0,0}});
        while(!st.empty()){
            auto it=*st.begin();
            int dis=it.first;
            int a=it.second.first;
            int b=it.second.second;
            st.erase(st.begin());
            for(int i=0;i<4;i++){
                int x=dx[i]+a;
                int y=dy[i]+b;
                if(x>=0 && x<n && y>=0 && y<m){
                    int k=dis;
                    if(grid[x][y]==1)
                    k=k-1;
                    if(k>dist[x][y]){
                        st.erase({dist[x][y],{x,y}});
                        dist[x][y]=k;
                        st.insert({dist[x][y],{x,y}});
                    }
                }
            }
        }
        return dist[n-1][m-1]>=1;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
       n=grid.size();
       m=grid[0].size();  
       return dijkstra(grid,health);
    }
};
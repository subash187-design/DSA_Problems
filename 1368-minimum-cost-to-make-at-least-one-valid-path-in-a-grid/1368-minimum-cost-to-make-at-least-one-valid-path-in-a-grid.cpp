class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
      
      int n=grid.size();
      int m=grid[0].size();
      multiset<pair<int,pair<int,int>>>st;
      vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
      st.insert({0,{0,0}});
      dist[0][0]=0;
      while(!st.empty()){
        auto it=*st.begin();
        st.erase(st.begin());
        int dis=it.first;
        int i=it.second.first;
        int j=it.second.second;
        if(i==n-1 && j==m-1)
        return dis;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(x>=0 && x<n && y>=0 && y<m){
                if(k+1==grid[i][j] && dis<dist[x][y]){
                    dist[x][y]=dis;
                    st.insert({dis,{x,y}});
                }
                else if(dis+1<dist[x][y]){
                    dist[x][y]=dis+1;
                    st.insert({dis+1,{x,y}});
                }
            }
        }
      }  
      return -1;
    }
};
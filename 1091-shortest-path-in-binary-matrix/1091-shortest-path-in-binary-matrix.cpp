class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<pair<int,pair<int,int>>>st;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        st.insert({1,{0,0}});
        if(grid[0][0]==1) return -1;
        dist[0][0]=1;
        while(!st.empty()){
            auto it=*st.begin();
            int dis=it.first;
            int a=it.second.first;
            int b=it.second.second;
            st.erase(st.begin());
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(i==0 && j==0) continue;
                    else{
                        int x=a+i;
                        int y=b+j;
                        if(x>=0 && x<n && y>=0 && y<m){
                            if(grid[x][y]==0){
                                if(1+dis<dist[x][y]){
                                    st.erase({dist[x][y],{x,y}});
                                    dist[x][y]=1+dis;
                                    st.insert({dist[x][y],{x,y}});
                                }
                            }
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1]==INT_MAX?-1:dist[n-1][m-1];

    }
};
class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    long long dijkstra(int m,int n,vector<vector<int>>& penalty){
        vector<vector<vector<long long>>>dist(m,vector<vector<long long>>(n,vector<long long>(2,1e18)));
        set<pair<long long,pair<pair<long long,long long>,long long>>>st;
        st.insert({1,{{0,0},1}});
        dist[0][0][1]=1;
        while(st.size()){
            auto a=*st.begin();
            st.erase(st.begin());
            long long d=a.first;
            int i=a.second.first.first;
            int j=a.second.first.second;
            int p1=a.second.second;
            int p2=1-p1;
            long long w= d+penalty[i][j];
            if (w<dist[i][j][p2]) {
                st.erase({dist[i][j][p2], {{i, j}, p2}});
                dist[i][j][p2] = w;
                st.insert({w, {{i, j}, p2}});
            }
            if(p1%2==0){
                for(int k=0;k<2;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    long long c=(x+1)*(y+1)+d;
                    if(x>=0 && x<m && y>=0 && y<n){
                    if(c<dist[x][y][p2]){
                        st.erase({dist[x][y][p2],{{x,y},p2}});
                        dist[x][y][p2]=c;
                        st.insert({c,{{x,y},p2}});
                    }
                    }
                }
                for(int k=2;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    long long c=((x+1)*(y+1))+penalty[i][j]+d;
                    if(x>=0 && x<m && y>=0 && y<n){
                    if(c<dist[x][y][p2]){
                        st.erase({dist[x][y][p2],{{x,y},p2}});
                        dist[x][y][p2]=c;
                        st.insert({c,{{x,y},p2}});
                    }
                    }
                }
                
            }
            else{
               for(int k=2;k<4;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    long long c=((x+1)*(y+1))+d;
                    if(x>=0 && x<m && y>=0 && y<n){
                    if(c<dist[x][y][p2]){
                        st.erase({dist[x][y][p2],{{x,y},p2}});
                        dist[x][y][p2]=c;
                        st.insert({c,{{x,y},p2}});
                    }
                    }
                }
                for(int k=0;k<2;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                   long long c=(x+1)*(y+1)+penalty[i][j]+d;
                    if(x>=0 && x<m && y>=0 && y<n){
                    if(c<dist[x][y][p2]){
                        st.erase({dist[x][y][p2],{{x,y},p2}});
                        dist[x][y][p2]=c;
                        st.insert({c,{{x,y},p2}});
                    }
                    }
                } 
            }
            
        }
        long long ans=min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
        return ans;
    }
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
      return dijkstra(m,n,penalty);  
    }
};
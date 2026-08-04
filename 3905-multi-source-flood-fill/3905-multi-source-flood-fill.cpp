class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void bfs(int n,int m,vector<vector<int>>& source){
    vector<vector<int>>time(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(source[i][j]!=0){
            que.push({{i,j},0});
            time[i][j]=0;
            }
        }
    }
    while(!que.empty()){
        int a=que.front().first.first;
        int b=que.front().first.second;
        int c=que.front().second;
        que.pop();
        for(int k=0;k<4;k++){
            int x=a+dx[k];
            int y=b+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                if(source[x][y]==0){
                    source[x][y]=source[a][b];
                    que.push({{x,y},c+1});
                    time[x][y]=c+1;
                }
                else if(c+1==time[x][y] && source[x][y]<source[a][b]){
                    source[x][y]=source[a][b];
                }

            }
        }

    }
    }
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>>source(n, vector<int>(m,0));
        for(int i=0;i<sources.size();i++){
           int a=sources[i][0];
           int b=sources[i][1];
           int c=sources[i][2];
           source[a][b]=c;
        }
       bfs(n,m,source);
       return source; 
    }
};
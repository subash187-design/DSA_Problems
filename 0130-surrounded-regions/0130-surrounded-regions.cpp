class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    void solve(vector<vector<char>>& board) {
      int n=board.size();
      int m=board[0].size();
      vector<vector<int>>vis(n,vector<int>(m,0));
      queue<pair<int,int>>que;
      for(int i=0;i<n;i++){
        if(board[i][0]=='O'){
        que.push({i,0});
        vis[i][0]=1;
        }
      }
      for(int i=0;i<m;i++){
        if(board[0][i]=='O' && !vis[0][i]){
        que.push({0,i});
        vis[0][i]=1;
        }
      }
      for(int i=0;i<n;i++){
        if(board[i][m-1]=='O' && !vis[i][m-1]){
        que.push({i,m-1});
        vis[i][m-1]=1;
         }
      }
      for(int i=0;i<m;i++){
       
        if(board[n-1][i]=='O' && !vis[n-1][i]){
        que.push({n-1,i});
        vis[n-1][i]=1;
        }
      }
      while(!que.empty()){
        int a=que.front().first;
        int b=que.front().second;
        que.pop();
        for(int i=0;i<4;i++){
            int x=a+dx[i];
            int y=b+dy[i];
            
            if(x>=0 && x<n && y>=0 && y<m){
                if(!vis[x][y] && board[x][y]=='O'){
                    que.push({x,y});
                    vis[x][y]=1;
                }
            }
        }

      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && vis[i][j]==0)
            board[i][j]='X';
        }
      }
      
    }
};
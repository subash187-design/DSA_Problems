class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int bfs(vector<vector<int>>& board,vector<vector<int>>& tar){
        int n=board.size();
        int m=board[0].size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        queue<tuple<vector<vector<int>>,int,int,int>>que;
        map<vector<vector<int>>,int>mp;
        mp[board]=1;
        que.push({board,a,b,0});
        while(!que.empty()){
            auto[curr,a,b,cnt]=que.front();
            que.pop();
            if(curr==tar)
            return cnt;
            for(int k=0;k<4;k++){
                    int i=dx[k]+a;
                    int j=dy[k]+b;
                    if(i>=0 && i<n && j>=0 && j<m){
                    swap(curr[i][j],curr[a][b]);
                    if(mp[curr]==0){
                        que.push({curr,i,j,cnt+1});
                        mp[curr]=1;
                    }
                    swap(curr[i][j],curr[a][b]);
                    }
                
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
     vector<vector<int>>tar{{1,2,3},{4,5,0}};
     return bfs(board,tar);   
    }
};
class Solution {
public:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    int n,m;
    bool dfs(int i,int j,int a,vector<vector<char>>& board, string word,vector<vector<int>>&vis){
        if(a>=word.size())
        return true;
        if(word[a]!=board[i][j])
        return false;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]){
                if(dfs(x,y,a+1,board,word,vis))
                return true;
            }
        }
        vis[i][j]=0;
        if(a+1>=word.size()) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int res=false;
        n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                res=res || dfs(i,j,0,board,word,vis);
            }
        }
        return res;
    }
};
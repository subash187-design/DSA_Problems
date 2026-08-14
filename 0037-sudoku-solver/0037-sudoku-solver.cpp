class Solution {
public:
    bool check(char ch,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==ch)
            return false;
            if(board[i][col]==ch)
            return false;
            int a=3*(row/3)+(i/3);
            int b=3*(col/3)+(i%3);
            if(board[a][b]==ch)
            return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(check(ch,i,j,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
     solve(board);   
    }

};
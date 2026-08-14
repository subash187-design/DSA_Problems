class Solution {
    vector<vector<string>> res;

public:
    bool check(int row,int col,int n,vector<string>&temp){
        int origRow=row;
        int origCol=col;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=origRow;
        col=origCol;
        while(row<n && col>=0){
            if(temp[row][col]=='Q') return false;
            
            row++;
            col--;
        }
        row=origRow;
        col=origCol;
        while(col>=0){
            if(temp[row][col]=='Q') return false;
            col--;
        
       }
       return true;

    }
    void solve(int i, int n, vector<string>& temp) {
        if (i == n) {
            res.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(check(j,i,n,temp)){
                temp[j][i]='Q';
                solve(i+1,n,temp);
                temp[j][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string a;
            for (int j = 0; j < n; j++) {
                a += '.';
            }
            temp.push_back(a);
        }
        solve(0, n, temp);
        return res;
    }
};
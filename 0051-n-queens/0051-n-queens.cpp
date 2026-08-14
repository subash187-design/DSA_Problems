class Solution {
    vector<vector<string>>res;

public:
    void solve(int i, int n, vector<string>& temp,vector<int>&row,vector<int>&upper,vector<int>&lower) {
        if (i == n) {
            res.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(lower[i+j]==0 && row[j]==0 && upper[(j-i)+(n-1)]==0){
                temp[j][i]='Q';
                lower[i+j]=1;
                upper[(j-i)+(n-1)]=1;
                row[j]=1;
                solve(i+1,n,temp,row,upper,lower);
                temp[j][i]='.';
                lower[i+j]=0;
                upper[(j-i)+(n-1)]=0;
                row[j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string a;
            for (int j = 0; j < n; j++) {
                a += '.';
            }
            temp.push_back(a);
        }
        vector<int>row(n,0);
        vector<int>upper((1<<n)-1,0);
        vector<int>lower((1<<n)-1,0);
        solve(0, n, temp,row,upper,lower);
        return res;
    }
};
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int i=0;
        int j=0;
        vector<int>res;
        bool flag=1;
        while(i>=0 && i<n && j>=0 && j<m){
            if(flag){
                if(j==m-1){
                    res.push_back(mat[i][j]);
                    i++;
                    flag=0;
                }
                else if(i==0){
                    res.push_back(mat[i][j]);
                    flag=0;
                    j++;
                }
                else{
                res.push_back(mat[i][j]);
                i--;
                j++;
                }
            }
            else{
                if(i==n-1){
                    res.push_back(mat[i][j]);
                    j++;
                    flag=1;
                }
                else if(j==0){
                    res.push_back(mat[i][j]);
                    i++;
                    flag=1;
                }
                else{
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};
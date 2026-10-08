class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
      int n = queries.size();
      vector<int>res(n,0);
      vector<int>perm(m,0);
      for(int i = 1; i <= m ; i++){
        perm[i-1] = i;
      }  
      for(int i = 0; i < n ;i++){
        int k = -1;
        for(int j = 0; j < m; j++){
            if(perm[j] == queries[i]){
                k = j;
                break;
            }
        }
        res[i] = k;
        perm.erase(perm.begin() + k);
        perm.insert(perm.begin(), queries[i]);
      }
      return res;
    }
};
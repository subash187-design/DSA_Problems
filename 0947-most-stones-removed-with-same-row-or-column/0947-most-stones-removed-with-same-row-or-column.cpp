class DSU{
    public:
    vector<int>par;
    vector<int>sz;
    void solve(int n){
        par.resize(n);
        sz.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int find(int n){
        if(par[n]==n)
        return n;
        return par[n]=find(par[n]);
    }

    void merge(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y)
        return ;
        if(sz[x]>sz[y])
        {
            par[y]=x;
            sz[x]+=sz[y];
        }
        else{
            par[x]=y;
            sz[y]+=sz[x];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DSU dsu;
        int n=stones.size();
        dsu.solve(maxRow+maxCol+2);
        unordered_map<int,int>mp;
        for(auto it:stones){
            int row=it[0];
            int col=maxRow+it[1]+1;
            dsu.merge(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        int res=0;
        for(auto it:mp){
            if(dsu.find(it.first)==it.first){
             res++;
            }
        }
        return n-res;
    }
};
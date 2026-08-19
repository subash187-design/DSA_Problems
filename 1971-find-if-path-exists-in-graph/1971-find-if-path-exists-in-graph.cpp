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
        if(n==par[n])
        return n;
        return par[n]=find(par[n]);
    }

    void merge(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y)
        return;
        if(sz[x]>sz[y]){
            par[y]=x;
            sz[x]=sz[x]+sz[y];
        }
        else {
            par[x]=y;
            sz[y]=sz[y]+sz[x];
        }

    }

};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu;
        dsu.solve(n);
        for(auto &it:edges){
            int a=it[0];
            int b=it[1];
            dsu.merge(a,b);
        }
        int x=dsu.find(source);
        int y=dsu.find(destination);
        return x==y;
    }
};
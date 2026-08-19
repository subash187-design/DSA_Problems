class DSU{
    public:
    vector<int>par;
    vector<int>sz;
    void solve(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }

    int find(int n){
        if(n==par[n])
        return n;
        return par[n]=find(par[n]);
    }

    bool merge(int a,int b){
        int x=find(a);
        int y=find(b);
        if(x==y)
        return false;
        if(sz[x]>sz[y]){
            sz[x]=sz[x]+sz[y];
            par[y]=x;
        }
        else{
            sz[y]=sz[y]+sz[x];
            par[x]=y;
        }
        return true;
    }
};



class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu;
        dsu.solve(n);
        for(auto i:edges){
            if(!dsu.merge(i[0],i[1]))
            return i;
        }
        return {};
    }
};
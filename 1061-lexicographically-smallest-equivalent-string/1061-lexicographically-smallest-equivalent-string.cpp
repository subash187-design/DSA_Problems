class DSU{
    public:
    vector<int>par;
    vector<int>sz;
    void solve(){
        par.resize(26);
        sz.resize(26,1);
        for(int i=0;i<26;i++){
            par[i]=i;
        }
    }
    int find(int n){
        if(n==par[n])
        return n;
        return par[n]=find(par[n]);
    }

    void merge(char ch1,char ch2){
        int a=ch1-'a';
        int b=ch2-'a';
        int x=find(a);
        int y=find(b);
        if(x==y) return;
        if(x<y){
            par[y]=x;
            sz[x]=sz[x]+sz[y];
        }
        else{
            par[x]=y;
            sz[y]=sz[x]+sz[y];
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu;
        dsu.solve();
        int n=s1.size();
        for(int i=0;i<n;i++){
            dsu.merge(s1[i],s2[i]);
        }
        string res="";
        for(int i=0;i<baseStr.size();i++){
            int k=baseStr[i]-'a';
            int x=dsu.find(k);
            res+=(x+'a');
        }
        return res;
    }
};
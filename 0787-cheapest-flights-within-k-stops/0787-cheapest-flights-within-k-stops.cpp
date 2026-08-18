class Solution {
public:
    int res=INT_MAX;
    int dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src, int dst, int k){
        vector<int>dist(n,INT_MAX);
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{0,src}});
        while(!st.empty()){
            auto it=*st.begin();
            int x=it.first;
            int dis=it.second.first;
            int node=it.second.second;
           
            st.erase(st.begin());
            for(auto i:adj[node]){
                int nod=i.first;
                int wt=i.second;
                if(nod==dst){
                    res=min(res,dis+wt);
                }
                else if(x>=k)
                continue;
                else if(dis+wt<dist[nod]){
                    dist[nod]=dis+wt;
                    st.insert({x+1,{dist[nod],nod}});
                }
            }
           
        }
         return res;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int a=flights[i][0];
            int b=flights[i][1];
            int c=flights[i][2];
            adj[a].push_back({b,c});
        }
        dijkstra(n,adj,src,dst,k);
        return res==INT_MAX?-1:res;
    }
};
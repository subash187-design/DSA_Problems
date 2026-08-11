class Solution {
public:
    int n,m;
    int dx[2]={0,1};
    int dy[2]={1,0};
    bool check(vector<vector<int>>&dungeon,int mid){
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>>remaining(n,vector<int>(m,INT_MIN));
        mid=mid+dungeon[0][0];
        pq.push({mid,{0,0}});
        if(mid<=0) return false;
        remaining[0][0]=mid;
        while(!pq.empty()){
            auto it=pq.top();
            int health=it.first;
            int i=it.second.first;
            int j=it.second.second;
            pq.pop();
            if(i==n-1 && j==m-1 &&health>0)
            return true;
            for(int k=0;k<2;k++){
                int x=dx[k]+i;
                int y=dy[k]+j;
                if(x>=0 && x<n && y>=0 && y<m){
                    int affect=dungeon[x][y];
                    if(health+affect>0 &&health+affect>=remaining[x][y]){
                       remaining[x][y]=health+affect;
                       pq.push({remaining[x][y],{x,y}}); 
                    }
                }
            }
        }
        return false;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int l=1;
      int sum=0;
      int ans=1;
      n=dungeon.size();
      m=dungeon[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dungeon[i][j]<0)
            sum+=dungeon[i][j];
        }
      }

      int r=abs(sum)+1;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(check(dungeon,mid)){
            ans=mid;
            r=mid-1;
        }
        else
        l=mid+1;
      }
      return ans;
    }
};
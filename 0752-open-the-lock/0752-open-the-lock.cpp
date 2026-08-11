class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> mp;
        for (string i : deadends) {
            mp[i]++;
        }
        queue<pair<string, int>> que;
        string x = "0000";
        if(mp[x]==1) return -1;
        mp[x]=1;
        que.push({x, 0});
        while (!que.empty()) {
            string a = que.front().first;
            int b = que.front().second;
            cout<<a<<" "<<b<<endl;
            if(a==target)
            return b;
            que.pop();
            for(int i=0;i<4;i++){
                string temp=a;
                int a=temp[i]-'0';
                int front=a+1;
                int back=a-1;
                if(front==10) front=0;
                if(back==-1) back=9;
                temp[i]=front+'0';
                if(mp[temp]==0){
                    que.push({temp,b+1});
                    mp[temp]=1;
                }
                temp[i]=back+'0';
                if(mp[temp]==0){
                    que.push({temp,b+1});
                    mp[temp]=1;
                }
            }

           
        }
        return -1;
    }
};
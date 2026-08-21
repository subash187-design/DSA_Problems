class Solution {
public:
    long long elevatorRequests(int k, int start,
                               vector<vector<int>>& requests) {
        int n = requests.size();
        vector<vector<int>> dist(1<<n,vector<int>(n, INT_MAX));
        priority_queue<pair<long long, pair<int, unsigned int>>,
                       vector<pair<long long, pair<int, unsigned int>>>,
                       greater<pair<long long, pair<int, unsigned int>>>>
            pq;
        for (int i = 0; i < requests.size(); i++) {
            int arrival = requests[i][0];
            int floor = requests[i][1];
            long long cost = max((long long)arrival, (long long)abs(floor - start));
            unsigned int mask = 0;
            mask= mask | 1<<i;
            dist[mask][i]=cost;
            pq.push({cost, {floor,mask }});  
        }
        while (!pq.empty()) {
            auto it = pq.top();
            long long cost = it.first;
            int floor = it.second.first;
            unsigned int mask = it.second.second;
            pq.pop();
            // cout<<floor<< " "<<cost<<endl;
            cout<<endl;
            if (popcount(mask) == n)
                return cost;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1)
                    continue;
                else{
                int nxtFloor = requests[i][1];
                int  arrival = requests[i][0];
               
                long long mx = max((long long)arrival,(long long) cost + abs(floor - nxtFloor));
                 int newMask=mask | (1<<i);
                 if(mx < dist[newMask][i]){
                  dist[newMask][i]=mx;
                  pq.push({mx, {nxtFloor, newMask}});
                 }
                }
            }
        }
        return -1;
    }
};
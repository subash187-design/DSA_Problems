class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        int n = nums1.size();
        int k = k1 + k2;
        for (int i = 0; i < n; i++) {
            int x = abs(nums1[i] - nums2[i]);
            //cout<<x<<" ";
            if (x && mp[x] == 0){
                pq.push(x);
            }
             if(x)
            mp[x]++;
        }
        //cout<<endl;
        while (!pq.empty() && k > 0) {
            int x = pq.top();
            //cout<<x<<" "<<mp[x]<<" "<<k<<endl;
            pq.pop();
            int cnt = mp[x];
            if (k >= cnt) {
                k -= cnt;
                mp[x] -= cnt;
                int temp = x - 1;
                if (temp && cnt) {
                    pq.push(temp);
                    mp[temp] += cnt;
                }
            } else {
                int curr = cnt - k;
                mp[x] = curr;
                mp[x - 1] += k;
                k = 0;
            }
        }
        long long res = 0;
        for (auto it : mp) {
            int val = it.first;
            pq.pop();
            int x = it.second;
            while (x--)
                res += (1LL * val * val);
        }
        return res;
    }
};
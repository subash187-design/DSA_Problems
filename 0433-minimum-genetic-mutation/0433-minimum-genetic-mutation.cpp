class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> arr = {'A', 'C', 'G', 'T'};
        unordered_set<string> st;
        for (string i : bank) {
            st.insert(i);
        }
        queue<pair<string, int>> que;
        que.push({startGene, 0});
        while (!que.empty()) {
            auto it = que.front();
            que.pop();
            string curr = it.first;
            int steps = it.second;
            if (curr == endGene)
                return steps;
            for(int i = 0; i < 8; i++){
                string temp = curr;
                for(int j = 0; j < 4; j++){
                    char ch = temp[i];
                    temp[i] = arr[j];
                    if(st.count(temp)){
                        st.erase(temp);
                        que.push({temp,steps+1});
                    }
                    temp[i] = ch;
                }
            }
        }
        return -1;
    }
};
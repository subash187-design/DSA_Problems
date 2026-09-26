class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> mp;
        for (auto i : knowledge) {
            string key = i[0];
            string value = i[1];
            mp[key] = value;
        }
        int n = s.size();
        string left = "";
        string curr = "";
        bool flag = true;
        for (int i = 0; i < n; i++) {
           // cout<<i<<" "<<curr<<" "<<left<<endl;
            if (s[i] == '(') {
                flag = false;
            } else if (s[i] == ')') {
                if (mp.find(left) != mp.end()) {
                    curr += mp[left];
                } else {
                    curr += '?';
                }
                left = "";
                flag = true;
            } else if (flag) {
                curr += s[i];
            } else {
                left += s[i];
            }
        }
        return curr;
    }
};
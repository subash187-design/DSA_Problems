class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string ,int > mp;
        string temp = "";
        int n = s.size();
        int l = 0;
        for(int r = 0; r < n; r++){
            temp += s[r];
            if((r - l + 1) > 10){
                temp.erase(0,1);
                l++;
            }
            if((r - l + 1) == 10){
            mp[temp]++;
            }
        }
        vector<string>res;
        for(auto it: mp){
            if(it.second > 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
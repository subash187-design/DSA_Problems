class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0;
        int r = 0;
        int n = chars.size();
        int i = 0;
        for (r; r < n; r++) {
            if (l == r)
                continue;
            if (chars[l] != chars[r]) {
                chars[i] = chars[l];
                i++;
                if ((r - l) > 1) {
                    int num = r - l;
                    string res = to_string(num);
                    for (auto it : res) {
                        chars[i] = it;
                        i++;
                    }
                }
                l = r;
            }
        }
        chars[i] = chars[l];
        i++;
        if ((r - l) > 1) {
            int num = r - l;
            string res = to_string(num);
            for (auto it : res) {
                chars[i] = it;
                i++;
            }
        }
        chars.erase(chars.begin()+i,chars.end());
        return chars.size();
    }
};
class Solution {
public:
    vector<string> res;
    void rec(string& temp, int cnt, int isZero, int n) {
        if (temp.size() >= n) {
            if (temp.size() >= 2 &&  cnt >= 1)
                res.push_back(temp);
            else if(temp.size() < 2)
                 res.push_back(temp);
            return;
        }
        for (int i = 0; i <= 1; i++) {
            if (i == 1) {
                temp.push_back('1');
                rec(temp, cnt + 1, 0, n);
                temp.pop_back();
            } else if (!isZero) {
                temp.push_back('0');
                rec(temp, cnt, 1, n);
                temp.pop_back();
            }
        }
    }
    vector<string> validStrings(int n) {
        string temp = "";
        rec(temp, 0, 0, n);
        return res;
    }
};
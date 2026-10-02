class Solution {
public:
    vector<int> res;
    void rec(int isStart, int n, string temp, int k) {
        if (n == 0) {
            int curr = stoi(temp);
            res.push_back(curr);
            return;
        }
        int i = 0;
        if (isStart == 0)
            i = 1;
        for (i; i <= 9; i++) {
            string curr = "";
            if (temp.size() == 0) {
                curr += (i + '0');
                rec(1, n - 1, curr, k);
            } else {
                curr += temp;
                int m = temp.size();
                int last = temp[m - 1] - '0';
                if (abs(i - last) == k) {
                    curr += (i + '0');
                    rec(isStart, n - 1, curr, k);
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string temp = "";
        rec(0, n, temp, k);
        return res;
    }
};
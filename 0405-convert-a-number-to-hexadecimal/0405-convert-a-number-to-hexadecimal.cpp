class Solution {
public:
    unsigned int func(int num) {
        unsigned int res = 0;
        num = -num;
        for (int i = 0; i <= 31; i++) {
            if (((num >> i) & 1) == 0) {
                res = res | (1 << i);
            }
        }
        return res + 1;
    }
    string toHex(int numb) {
        unsigned int num = numb;
        if (num < 0)
            num = func(numb);
        else if(num == 0)
            return "0";
        string res;
        while (num) {
            int temp = num % 16;
            if (temp <= 9) {
                res += (temp + '0');
            } else {
                temp = temp - 10;
                res += (temp + 'a');
            }
            num = num / 16;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
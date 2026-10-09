class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int i = 0;
        int carry = 0;
        while (i < 32) {
            int x = (a & (1 << i)) ? 1 : 0;
            int y = (b & (1 << i)) ? 1 : 0;
            int temp = (x ^ y) ^ carry;
            carry = (x & y) || (x & carry) || (y & carry);
            if (temp)
                ans = ans | (1 << i);
            int mask = 1;
            while (i & mask) {
                i = i ^ mask;
                mask <<= 1;
            }
            i = i ^ mask;
        }
        return ans;
    }
};
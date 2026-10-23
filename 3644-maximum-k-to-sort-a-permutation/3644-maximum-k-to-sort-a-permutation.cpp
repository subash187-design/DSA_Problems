class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = 0;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            bool temp = false;
            if (num != i) {
                temp = true;
                for (int j = 0; j < 30; j++) {
                    if (!flag) {
                        if ((num >> j) & 1)
                            res = res | (1 << j);
                    } else {
                        if ((res >> j) & 1 && ((num >> j) & 1)) {
                            continue;
                        }
                        else {
                            if((res >> j) & 1)
                            res = res ^ (1 << j);
                        }
                    }
                }
            }
            if(temp){
                flag = true;
            }
        }
        return res;
    }
};
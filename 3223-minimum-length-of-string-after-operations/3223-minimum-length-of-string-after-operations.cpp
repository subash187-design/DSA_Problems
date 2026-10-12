class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i = 0; i < s.size(); i++){
            int x = s[i] - 'a';
            freq[x] ++;
        }
        int res = 0;
        for(int i = 0 ; i < 26; i++){
            if(freq[i] != 0){
                if(freq[i] > 2){
                    while(freq[i] > 2){
                        freq[i] -= 2;
                    }
                    res += freq[i];
                }
                else{
                    res += freq[i];
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    string compressedString(string word) {
        string res = "";
        char ch = word[0];
        int cnt = 1;
        for(int i = 1; i < word.size(); i++){
            if(word[i] == ch){
                if(cnt + 1 > 9){
                    res.push_back((char)(cnt + '0'));
                    res.push_back(ch);
                    cnt = 1;
                }
                else{
                    cnt++;
                }
            }
            else{
                res.push_back((char)(cnt + '0'));
                res.push_back(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        res.push_back((char)(cnt + '0'));
        res.push_back(ch);
        return res;
    }
};
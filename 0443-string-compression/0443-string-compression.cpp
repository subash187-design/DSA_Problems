class Solution {
public:
    int compress(vector<char>& chars) {
        string res = "";
        int l = 0;
        int r = 0;
        int n = chars.size();
        for(r ; r < n ; r++){
            if(l == r)
            continue;
            if(chars[l] != chars[r]){
                res += chars[l];
                if((r - l) > 1){
                    int num = r - l;
                    res += to_string(r-l);
                }
                l = r;
            }
        }
        res+=chars[l];
        if((r-l) > 1)
        res+=to_string(r-l);
        vector<char>ans(res.size());
        int i = 0;
        for(auto it:res){
            ans[i] = it;
            i++;
        }
        chars = ans;
        return ans.size();
    }
};
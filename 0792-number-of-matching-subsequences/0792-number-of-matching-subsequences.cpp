class Solution {
public:
    int res = 0;
    vector<vector<int>>mp;
    int m;
    int binary(int prev,vector<int>&arr){
        int l = 0;
        int n = arr.size();
        int r = n - 1;
        int ans = m;
        while(l <= r){
            int mid = l + ( r - l ) / 2;
            if(arr[mid] > prev){
                ans = arr[mid];
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    bool check(string& word){
        int n = word.size();
        int prev = -1;
        for(int i = 0 ; i < n ; i++){
            int k = binary(prev,mp[word[i] - 'a']);
            if(k == m)
            return false;
            prev = k;
        }
        return true;

    }
    int numMatchingSubseq(string s, vector<string>& words) {
        m = s.size();
        mp.resize(26);
        for (int i = 0; i < m; i++) {
            int ch = s[i] - 'a';
            mp[ch].push_back(i);
        }
        for(string word : words){
            if(check(word)){
                res++;
            }
        }
        return res;
    }
};
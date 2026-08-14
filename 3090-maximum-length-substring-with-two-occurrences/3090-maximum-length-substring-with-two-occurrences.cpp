class Solution {
public:
    int maximumLengthSubstring(string s) {
     int res=0;
     int l=0;
     unordered_map<int,int>mp;
     for(int r=0;r<s.size();r++){
        mp[s[r]]++;
        while(mp[s[r]]>2){
            mp[s[l]]--;
            l++;
        }
        res=max(res,r-l+1);
     }   
     return res;
    }
};
class Solution {
public:
    int maxVowels(string s, int k) {
       int l=0;
       int r=0;
       int res=0;
       int cnt=0;
       for(r;r<s.size();r++){
        if(s[r]=='a' || s[r]=='e' || s[r]=='i'|| s[r]=='o' || s[r]=='u'){
            cnt++;
        }
        if(r-l+1>k){
          if(s[l]=='a' || s[l]=='e' || s[l]=='i'|| s[l]=='o' || s[l]=='u')
            cnt--;
            l++;
        }   
        if(r-l+1==k)
        res=max(res,cnt);
        }
        
       return res;
    }
};
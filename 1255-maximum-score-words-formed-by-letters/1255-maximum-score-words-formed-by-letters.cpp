class Solution {
public:
    int res=0;
    void solve(vector<string>& words, vector<char>& letters, vector<int>& score){
      unordered_map<char,int>mp;
      for(auto ch:letters){
        mp[ch]++;
      } 
      int sm=0;
      bool flag=true;
      for(int i=0;i<words.size();i++){
        for(char ch:words[i]){
            if(mp[ch]==0){
                flag=false;
                break;
            }
            mp[ch]--;
            sm=sm+(score[ch-'a']);
        }
        if(!flag)
        break;
      }
      if(flag)
      res=max(res,sm);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        for(int i=0;i<(1<<n);i++){
            vector<string>curr;
            for(int pos=0;pos<n;pos++){
                if((i>>pos)&1){
                    curr.push_back(words[pos]);
                }
            }
            solve(curr,letters,score);
        }
        return res;
    }
};
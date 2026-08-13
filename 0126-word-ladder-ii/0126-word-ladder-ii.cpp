class Solution {
unordered_map<string,int>steps;
vector<vector<string>>res;
int n;
private:
   void rec(string curr,vector<string>&seq,string end){
    if(curr==end){
        reverse(seq.begin(),seq.end());
        res.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    string orig=curr;
    for(int i=0;i<n;i++){
        for(char ch='a';ch<='z';ch++){
            orig[i]=ch;
            // cout<<orig<<" "<<steps[orig]<<" "<<steps[curr]<<endl;
            if(steps.find(orig)!=steps.end() && steps[orig]+1==steps[curr]){
                seq.push_back(orig);
                rec(orig,seq,end);
                seq.pop_back();
            }
        }
        orig=curr;
    }
   }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(string& i:wordList)
        mp[i]++;
        queue<string>que;
        que.push(beginWord);
        steps[beginWord]=1;
        mp[beginWord]=0;
        n=beginWord.size();
        while(!que.empty()){
            string temp=que.front();
            que.pop();
            if(temp==endWord)  break;
            string orig=temp;
            for(int i=0;i<n;i++){
                for(char ch='a';ch<='z';ch++){
                    orig[i]=ch;
                    if(mp[orig]==1){
                        mp[orig]=0;
                        steps[orig]=steps[temp]+1;
                        que.push(orig);
                    }
                }
                 orig=temp;
            }
        }
        if(steps.find(endWord)!=steps.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            rec(endWord,seq,beginWord);
        }
        return res;
    }
};
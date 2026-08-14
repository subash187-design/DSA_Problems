class Solution {
vector<vector<string>>res;
public:
    bool check(string s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(int i,string s,vector<string>&temp){
        if(i==s.size())
        {
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
       vector<string>temp;
       solve(0,s,temp);
       return res; 
    }
};
class TrieNode {
public:
    int Stcnt;
    TrieNode* alpha[26];
    bool isEnd;
    TrieNode() {
        Stcnt = 0;
        for (int i = 0; i < 26; i++) {
            alpha[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    int n, m;
    vector<string> res;
    Trie(int n, int m) {
        this->n = n;
        this->m = m;
        root = new TrieNode();
    }
    void dfs(int i,int j,TrieNode* curr,string& temp,vector<vector<char>>&board,vector<vector<int>>&vis){
        // cout<<temp<<endl;
        if(curr -> isEnd == true){
            res.push_back(temp);
            erasee(temp);
        }
        vis[i][j] = 1;
        // cout<<i<<" "<<j<<" : "<<endl;
        for(int k  = 0; k < 4; k++){
            int x = dx[k] + i;
            int y = dy[k] + j;
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]){
                // cout<<x<<" "<<y<<endl;
                char ch = board[x][y];
                TrieNode* tp = curr -> alpha[ch - 'a'];
                if(curr -> alpha[ch - 'a'] != NULL  && tp -> Stcnt > 0){
                    temp.push_back(ch);
                    dfs(x,y,tp,temp,board,vis);
                    temp.pop_back();
                }
            }
        }
        vis[i][j] = 0;
    }
    void solve(vector<vector<char>>&board){
        TrieNode* curr = root;
        string temp = "";
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                char ch = board[i][j];
                TrieNode* tp = curr -> alpha[ch - 'a'];
                if(curr -> alpha[ch - 'a'] != NULL && tp -> Stcnt > 0){
                    temp.push_back(ch);
                    dfs(i,j,tp,temp,board,vis);
                    temp.pop_back();
                }
            }
        }
    }
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->alpha[word[i] - 'a'] == NULL) {
                curr->alpha[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->alpha[word[i] - 'a'];
            curr->Stcnt += 1;
        }
        curr->isEnd = true;
    }
    void erasee(string word){
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            curr = curr->alpha[word[i] - 'a'];
            curr -> Stcnt -= 1;
        }
        curr->isEnd = false;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int n = board.size();
        int m = board[0].size();
        Trie* trie = new Trie(n, m);
        for (auto it : words) {
            trie->insert(it);
        }
        trie->solve(board);
        return trie->res;
    }
};
class TrieNode {
public:
    TrieNode* num[10];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 10; i++) {
            num[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
public:
    TrieNode* root;
    vector<int> res;
    Trie() { root = new TrieNode(); }
    void insert(string& temp) {
        TrieNode* curr = root;
        for (int i = 0; i < temp.size(); i++) {
            if (curr->num[temp[i] - '0'] == NULL) {
                curr->num[temp[i] - '0'] = new TrieNode();
            }
            curr = curr->num[temp[i] - '0'];
        }
        curr -> isEnd = true;
    }
    void rec(TrieNode* curr,string& temp){
        if(curr -> isEnd)
        {
            int a = stoi(temp);
            res.push_back(a);
        }
        for(int i = 0; i <= 9; i++){
            char ch = i + '0';
            if (curr -> num[i] != NULL){
                temp.push_back(ch);
                rec(curr->num[i],temp);
                temp.pop_back();
            }
        }
    }
    void solve() {
        TrieNode* curr = root;
        string temp = "";
        for (int i = 0; i <= 9; i++) {
            char ch = i + '0';
            if (curr -> num[i] != NULL){
                temp.push_back(ch);
                rec(curr->num[i],temp);
                temp.pop_back();
            }
        }
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie* trie = new Trie();
        for (int i = 1; i <= n; i++) {
            string temp = to_string(i);
            trie->insert(temp);
        }
        trie->solve();
        return trie->res;
    }
};
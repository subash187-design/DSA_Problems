class TrieNode {
public:
    TrieNode* alpha[26];
    int Stcnt;
    TrieNode() {
        for (int i = 0; i < 26; i++)
            alpha[i] = NULL;
        Stcnt = 0;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insertt(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->alpha[word[i] - 'a'] == NULL) {
                curr->alpha[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->alpha[word[i] - 'a'];
            curr->Stcnt += 1;
        }
    }
    bool present(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            curr = curr->alpha[word[i] - 'a'];
            if(curr -> Stcnt == 0)
            return true;
        }
        return false;
    }
    void erasee(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.size() ; i++){
            curr = curr->alpha[word[i] - 'a'];
            curr->Stcnt -= 1;
        }
    }
};
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        Trie* trie = new Trie();
        int n = arr.size();
        for (int k = 0; k < n; k++) {
            string curr = arr[k];
            int m = curr.size();
            for (int i = 0; i < m; i++) {
                string temp = "";
                for (int j = i; j < m; j++) {
                    temp += curr[j];
                    trie->insertt(temp);
                }
            }
        }
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string word = arr[i];
            int m = word.size();
            for (int i = 0; i < m; i++) {
                string temp = "";
                for (int j = i; j < m; j++) {
                    temp += word[j];
                    trie->erasee(temp);
                }
            }
            string temp = "";
            for (int x = 0; x < m; x++) {
                string curr = "";
                for (int y = x; y < m; y++) {
                    curr += word[y];
                    if (trie->present(curr)) {
                        if (temp.size() == 0) {
                            temp = curr;
                        }
                        else if(curr.size() < temp.size() ){
                            temp = curr;
                        }
                        else if(temp.size() == curr.size() && curr < temp){
                            temp = curr;
                        }
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                string temp = "";
                for (int j = i; j < m; j++) {
                    temp += word[j];
                    trie->insertt(temp);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
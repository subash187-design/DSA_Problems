class TrieNode{
public:
bool isEnd;
TrieNode* alpha[26];
TrieNode(){
    isEnd=false;
    for(int i=0;i<26;i++){
        alpha[i]=NULL;
    }
}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
       TrieNode* curr=root;
       for(char ch:word){
        if(curr->alpha[ch-'a']==NULL){
            curr->alpha[ch-'a']=new TrieNode();
        }
        curr=curr->alpha[ch-'a'];
       } 
       curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            if(curr->alpha[ch-'a']==NULL)
            return false;
            curr=curr->alpha[ch-'a'];
        }
        return curr->isEnd==true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char ch:prefix){
            if(curr->alpha[ch-'a']==NULL)
            return false;
            curr=curr->alpha[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
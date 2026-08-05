class TrieNode{
    public:
    TrieNode* alpha[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++)
        alpha[i]=NULL;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(char ch:word){
            if(curr->alpha[ch-'a']==NULL)
            curr->alpha[ch-'a']=new TrieNode();
            curr=curr->alpha[ch-'a'];
        }
        curr->isEnd=true;
        
    }
    int rec(int i,string &word,TrieNode* curr){
        if(i==word.size())
        return curr->isEnd==true;
        int res=0;
        char ch;
        if(word[i]=='.'){
        for(int j=0;j<26;j++){
            if(curr->alpha[j]!=NULL){
                if(rec(i+1,word,curr->alpha[j])){
                    ch=j+'a';
                    res= true;
                    break;
                }
            }
        }
        }
        else{
            ch=word[i];
            if(curr->alpha[ch-'a']==NULL)
            res= false;
            else{
            curr=curr->alpha[ch-'a'];
            res= rec(i+1,word,curr);
            }
        }
        return res;
    }
    bool search(string word) {
       bool res=true;
       TrieNode* curr=root;
       return rec(0,word,curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
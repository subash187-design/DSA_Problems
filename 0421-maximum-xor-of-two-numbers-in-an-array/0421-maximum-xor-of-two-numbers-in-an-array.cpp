class TrieNode{
public:
    TrieNode* arr[2];
    TrieNode(){
        arr[0]=NULL;
        arr[1]=NULL;
    }
};
class Solution {
public:
    TrieNode* root=new TrieNode();
    void insert(int k,TrieNode* root){
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int bt=(k>>i)&1;
            if(curr->arr[bt]==NULL){
                curr->arr[bt]=new TrieNode();
            }
            curr=curr->arr[bt];
        }
    }
    int find(int k,TrieNode* root){
        TrieNode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bt=(k>>i)&1;
            int op=1-bt;
            if(curr->arr[op]!=NULL){
              ans=(1<<i)|ans;
              curr=curr->arr[op];  
            }
            else{
            curr=curr->arr[bt];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int i:nums){
            insert(i,root);
        }
        int mx=0;
        for(int i:nums){
            mx=max(mx,find(i,root));
        }
        return mx;
    }
};
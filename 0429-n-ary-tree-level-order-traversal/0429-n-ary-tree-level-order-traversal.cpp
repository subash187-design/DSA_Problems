/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>>res;
    void level(Node*root){
        if(root==NULL)
        return;
        queue<pair<Node*,int>>que;
        que.push({root,0});
        while(!que.empty()){
            Node* temp=que.front().first;
            int l=que.front().second;
            que.pop();
            for(auto i:temp->children){
                if(i!=NULL){
                if(l+1>=res.size()) res.push_back({});
                res[l+1].push_back(i->val);
                que.push({i,l+1});
                }
            }
            
        }

    }
    vector<vector<int>> levelOrder(Node* root) {
      if(root==NULL)
      return {};
      res.push_back({});
      res[0].push_back(root->val);
      level(root);
      return res;  
    }
};
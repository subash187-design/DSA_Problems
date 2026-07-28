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
    vector<int>res;
    void post(Node* root){
        if(root==NULL)
        return;
        for(Node* i:root->children){
            post(i);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
       if(root==NULL)
       return {};
       post(root);
       return res; 
    }
};
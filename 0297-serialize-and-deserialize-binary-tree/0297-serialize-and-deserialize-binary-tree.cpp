/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        string s;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr=que.front();
            que.pop();
            if(curr!=NULL)
            {
                s+=to_string(curr->val);
                s+=',';
                 que.push(curr->left);
                que.push(curr->right);
            }
            else
            s=s+'$'+',';
        }
        return s;
        
    }
    TreeNode* deserialize(string data) {
    if(data=="")
    return NULL;
       stringstream ss(data);
       string s;
       getline(ss,s,',');
       TreeNode* root=new TreeNode(stoi(s));
       queue<TreeNode*>que;
       que.push(root);
       while(!que.empty()){
        auto it=que.front();
        TreeNode* curr=it;
        que.pop();
        getline(ss,s,',');
        if(s=="$"){
            curr->left=NULL;
        }
        else
        {
             curr->left=new TreeNode(stoi(s));
             que.push(curr->left);
        }
        getline(ss,s,',');
        if(s=="$"){
            curr->right=NULL;
        }
        else
        {
             curr->right=new TreeNode(stoi(s));
             que.push(curr->right);
        }
        
        }
       return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
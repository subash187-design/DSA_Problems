class Solution {
public:
    vector<string>res;
    void rec(int op,int cl,string temp){
        if(op==0 && cl==0)
        {
            res.push_back(temp);
            return ;
        }
        if(op>0)
        rec(op-1,cl+1,temp+'(');
        if(cl>0){
            rec(op,cl-1,temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
      string temp="";
      rec(n,0,temp); 
      return res; 
    }
};
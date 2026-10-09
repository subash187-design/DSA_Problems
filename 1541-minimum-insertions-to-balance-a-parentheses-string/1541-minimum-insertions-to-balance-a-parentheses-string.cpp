class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int n = s.size();
        stack<int>st;
        for(int i = 0; i < n;){
            if(s[i] == '('){
                //cout<<i<<endl;
                st.push(i);
                i++;
            }
            else if(s[i] == ')'){
                //cout<<i<<endl;
                if(i + 1 < n && s[i+1] == ')'){
                    //cout<<"hi"<<endl;
                    if(!st.empty())
                    st.pop();
                    else
                    res+=1;
                    i+=2;
                }
                else{
                    //cout<<"hello"<<endl;
                    if(!st.empty()){
                    st.pop();
                    res+=1;
                    }
                    else
                    res+=2;
                    i+=1;

                }
            }
        }
        res += (st.size() * 2);
        return res;
    }
};
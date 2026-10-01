class Solution {
public:
    bool isValid(string s) {
        vector<char>str;
        int j=s.size();
        int n=0;
        for(int i=0;i<j;i++)
        {
            if(s[i]=='('  ||  s[i]=='{' || s[i]=='[' )
            {
            n=0;
            str.push_back(s[i]);
            }
            else if(s[i]==')'  ||  s[i]=='}'  || s[i]==']')
            {
                if(str.empty())
                return false;
                else if(str.back()=='(' &&  s[i]==')')
                {
                n=1;
                str.pop_back();
                }
                else if(str.back()=='{'   &&  s[i]=='}')
                {
                    str.pop_back();
                    n=1;
                }
                else if(str.back()=='['  &&   s[i]==']')
                {
                    str.pop_back();
                    n=1;
                }
               
                else
                return false;
            }
            else
            {
            str.pop_back();
            n=0;
            }

        }
         if(!str.empty())
         return false;
        if(n==1)
        return true;
        else
        return false;

        
    }
};
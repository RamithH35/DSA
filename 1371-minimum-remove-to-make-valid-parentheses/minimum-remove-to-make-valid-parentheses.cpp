class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int opencount=0;
        string st=s;
        for(int i=0;i<st.size();i++)
        {
            char c=st[i];
            if(c=='(')
                opencount++;
            else if(c==')')
            {
                if(opencount==0)
                    st[i]='*';
                else
                    opencount--;
            }
        }
        if(opencount>0)
        {
            int n=st.size()-1;
            while(opencount>0)
            {
                if(st[n]=='(')
                {
                    opencount--;
                    st[n]='*';
                }
                n--;
            }
        }
        string res="";
        for(char c:st)
        {
            if(c!='*')
                res+=c;
        }
        return res;

    }
};
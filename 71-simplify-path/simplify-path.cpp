class Solution {
public:
    string simplifyPath(string path) {
        string curstr="";
        stack<string>st;
        for(char c:path)
        {
            if(c=='/'&&curstr.empty())
                continue;
            else if(c=='/' && !curstr.empty())
            {
                if(curstr==".")
                {
                    curstr="";
                }
                else if(curstr=="..")
                {
                    if(!st.empty())
                        st.pop();
                    curstr="";
                }
                else
                {
                    st.push(curstr);
                    curstr="";
                }
                
            }
            else
                curstr+=c;

        }
        if(curstr=="..")
        {
            if(!st.empty())
                st.pop();
        }
        else if(curstr!="." && !curstr.empty())
            st.push(curstr);

        if(st.empty())
            return "/";
        string ans=st.top();
        st.pop();
        while(!st.empty())
        {
            string temp=st.top();
            st.pop();
            ans=temp+"/"+ans;
        }
        return "/"+ans;
           
    }
};
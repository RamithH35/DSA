class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c!=']')
                st.push(c);
            else
            {
                string curstr="";
                while(!st.empty()&&st.top()!='[')
                {
                    curstr+=st.top();
                    st.pop();
                }
                reverse(curstr.begin(),curstr.end());
                st.pop();
                string n="";
                while(!st.empty()&&isdigit(st.top()))
                {
                    n+=st.top();
                    st.pop();
                }
                reverse(n.begin(),n.end());
                int num=stoi(n);
                string temp=curstr;
                for(int i=1;i<num;i++)
                    curstr+=temp;
                for(char c:curstr)
                    st.push(c);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
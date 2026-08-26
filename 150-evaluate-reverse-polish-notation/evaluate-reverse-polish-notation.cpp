class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
            string s=tokens[i];
            if(s=="+")
            {
                int b=stoi(st.top());st.pop();
                int a=stoi(st.top());st.pop();
                int res=a+b;
                st.push(to_string(res));
            }
            else if(s=="-")
            {
                int b=stoi(st.top());st.pop();
                int a=stoi(st.top());st.pop();
                int res=a-b;
                st.push(to_string(res));
            }
            else if(s=="*")
            {
                int b=stoi(st.top());st.pop();
                int a=stoi(st.top());st.pop();
                int res=a*b;
                st.push(to_string(res));
            }
            else if(s=="/")
            {
                int b=stoi(st.top());st.pop();
                int a=stoi(st.top());st.pop();
                int res=a/b;
                st.push(to_string(res));
            }
            else
                st.push(s);
        }
        return stoi(st.top());
    }
};
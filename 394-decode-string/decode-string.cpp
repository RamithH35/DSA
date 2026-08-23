class Solution {
public:
    string decodeString(string s) {
        string curstr="";
        int n=0;
        stack<int>s1;
        stack<string>s2;
        for(char c:s)
        {
            if(isdigit(c))
                n=(n*10)+(c-'0');
            else if(c =='[')
            {
                s1.push(n);
                s2.push(curstr);
                n=0;
                curstr="";
            }
            else if(c==']')
            {
                int m=s1.top();
                s1.pop();
                string temp=curstr;
                for(int i=1;i<m;i++)
                    curstr+=temp;
                string prev=s2.top();
                s2.pop();
                curstr=prev+curstr;
            }
            else
                curstr+=c;
        }
        return curstr;
    }
};
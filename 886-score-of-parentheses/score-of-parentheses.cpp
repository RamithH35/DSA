class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0;
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(c=='(')
                depth++;
            else
            {
                if(s[i-1]=='(')
                    sum+= pow(2,depth-1);
                depth--;
            }
        }
        return sum;
    }
};
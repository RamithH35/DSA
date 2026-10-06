class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance=0;
        int right=0;
        for(char c:s)
        {
            if (c=='(')
                balance++;
            else
            {
                balance--;
                if(balance<0)
                {
                    right++;
                    balance=0;
                }
            }
        }
        return balance+right;
    }
};
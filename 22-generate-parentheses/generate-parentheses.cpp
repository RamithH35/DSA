class Solution {
public:
    void generate(string r,int open,int close,int n,vector<string>&res)
    {
        if(open==n && close==n)
        {
            res.push_back(r);
            return;
        }
        if(open<n)
        {
            generate(r+"(",open+1,close,n,res);
        }
        if(close<open)
            generate(r+")",open,close+1,n,res);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generate("",0,0,n,res);
        return res;
    }
};
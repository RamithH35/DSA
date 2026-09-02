class Solution {
public:
    void generate(string s,int ind,int n,string d,vector<string>&fn,vector<string>&res)
    {
        if(ind==n)
        {
            res.push_back(s);
            return;
        }
        int x = d[ind]-'0';
        string y=fn[x];
        for(int i=0;i<fn[x].size();i++)
        {
            generate(s+y[i],ind+1,n,d,fn,res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>fn={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        string s="";
        generate(s,0,digits.size(),digits,fn,res);
        return res;
    }
};
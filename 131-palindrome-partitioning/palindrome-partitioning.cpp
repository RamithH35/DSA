class Solution {
public:
    bool ispalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void helper(int index,string s,vector<string>&ds,vector<vector<string>>&res)
    {
        if(index==s.size())
        {
            res.push_back(ds);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(ispalindrome(s,index,i))
            {
                ds.push_back(s.substr(index,i-index+1));
                helper(i+1,s,ds,res);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>ds;
        helper(0,s,ds,res);
        return res;
    }
};
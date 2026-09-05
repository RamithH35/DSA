class Solution {
public:
    bool helper(int index,string &s,unordered_set<string>&mp,vector<int>&dp)
    {
        if(index==s.size())
            return true;
        if(dp[index]!=-1)
            return dp[index];
        for(int i=index;i<s.size();i++)
        {
            string st = s.substr(index,i-index+1);
            if(mp.find(st)!=mp.end())
            {
                if(helper(i+1,s,mp,dp))
                {
                    dp[index]=1;
                    return true;
                }
            }
        }
        dp[index]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return helper(0,s,mp,dp);
    }
};
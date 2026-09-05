class Solution {
public:
    bool solve(int idx, string &s, unordered_set<string> &st,
               vector<int> &dp) {
        
        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string temp = "";

        for (int i = idx; i < s.size(); i++) {
            temp += s[i];

            if (st.find(temp) != st.end()) {
                if (solve(i + 1, s, st, dp))
                    return dp[idx] = 1;
            }
        }

        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};
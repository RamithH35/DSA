class Solution {
public:
    string removeStars(string s) {
        string ans=s;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
                j--;
            else
                ans[j++]=s[i];
        }
        return ans.substr(0,j);
    }
};
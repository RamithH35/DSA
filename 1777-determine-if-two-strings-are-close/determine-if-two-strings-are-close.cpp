class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        vector<int>w1(26,0);
        vector<int>w2(26,0);
        for (int i=0;i<word1.size();i++)
        {
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
        for(int j=0;j<26;j++)
        {
            if(w1[j]==0 && w2[j]>0)
                return false;
            if(w2[j]==0 && w1[j]>0)
                return false;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        for(int k=25;k>=0;k--)
        {
            if(w1[k]!=w2[k])
                return false;
        }
        return true;
        
    }
};
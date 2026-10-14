class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word)
            words.push_back(word);
        if(pattern.size()!=words.size())
            return false;
        unordered_map<char,string>mp;
        unordered_map<string,char>rev;
        for(int i=0;i<pattern.size();i++)
        {
            char c=pattern[i];
            string w=words[i];
            if(mp.find(c)!=mp.end() && mp[c]!=w)
                return false;
            if(rev.find(w)!=rev.end() && rev[w]!=c)
                return false;
            rev[w]=c;
            mp[c]=w;
        }
        return true;
        
    }
};
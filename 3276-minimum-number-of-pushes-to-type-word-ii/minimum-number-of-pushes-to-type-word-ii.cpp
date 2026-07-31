class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char c : word)
        {
            mp[c-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(mp[i]==0) break;
            cnt+=mp[i]*(i/8+1);
        }
        return cnt;
    }
};
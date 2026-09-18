class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char>mp;
        int cnt=0;
        for(char c:jewels)
            mp.insert(c);
        for(char x:stones)
        {
            if(mp.find(x)!=mp.end())
                cnt++;
        }
        return cnt;
    }
};
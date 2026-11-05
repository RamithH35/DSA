class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>map;
        for(int &x:arr)
            mp[x]++;
        for(auto &y:mp)
        {
            if(map.find(y.second)!=map.end())
                return false;
            map[y.second]++;
        }
        return true;
    }
};
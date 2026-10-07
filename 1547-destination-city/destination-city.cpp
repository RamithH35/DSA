class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        for(auto &x:paths)
        {
            if(mp.find(x[0])==mp.end() || mp[x[0]]==1)
                mp[x[0]]=2;
            if(mp.find(x[1])==mp.end())
                mp[x[1]]=1;
        }
        for(auto &x:paths)
        {
            if(mp[x[1]]==1)
                return x[1];
        }
        return "";
    }
};
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>cities;
        for(auto &x:paths)
        {
            cities.insert(x[0]);
        }
        for(auto &x:paths)
        {
            if(cities.find(x[1])==cities.end())
                return x[1];
        }
        return "";
    }
};
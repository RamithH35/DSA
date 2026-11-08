class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>res;
        for(int x:arr1)
            mp[x]++;
        for(int y:arr2)
        {
            res.insert(res.end(),mp[y],y);
            mp.erase(y);
        }
        for(auto z:mp)
        {
            res.insert(res.end(),z.second,z.first);
        }
        return res;
    }
};
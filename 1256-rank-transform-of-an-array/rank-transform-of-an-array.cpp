class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
            return arr;
        vector<int>c=arr;
        unordered_map<int,int>mp;
        sort(c.begin(),c.end());
        int rank=1;
        mp[c[0]]=1;
        for(int i=1;i<c.size();i++)
        {
            if(c[i]!=c[i-1])
            {
                rank++;
                mp[c[i]]=rank;
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            int x=mp[arr[i]];
            c[i]=x;
        }
        return c;
    }
};
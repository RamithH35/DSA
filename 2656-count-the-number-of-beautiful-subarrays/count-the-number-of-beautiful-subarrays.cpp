class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int res=0;
        for(int &x:nums)
        {
            res^=x;
            if(mp.find(res)!=mp.end())
                ans+=mp[res];
            mp[res]++;
        }
        return ans;
    }
};
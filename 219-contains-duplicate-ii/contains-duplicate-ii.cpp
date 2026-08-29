class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        for(int i=1;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end() && i-mp[nums[i]]<=k)
                return true;
            mp[nums[i]]=i;
        }
        return false;
    }
};
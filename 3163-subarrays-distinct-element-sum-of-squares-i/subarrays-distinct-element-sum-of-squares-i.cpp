class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int>mp;
            int distinct=0;
            for(int j=i;j<nums.size();j++)
            {
                if(!mp.count(nums[j]))
                {
                    distinct++;
                }
                mp[nums[j]]++;
                ans+=distinct*distinct;
            }
        }
        return ans;
    }

};
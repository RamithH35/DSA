class Solution {
public:
    int atmostkdistinct(vector<int>&nums,int k)
    {
        unordered_map<int,int>mp;
        int distinct=0;
        int s=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            if(mp.find(nums[right])==mp.end())
                distinct++;
            mp[nums[right]]++;
            while(distinct>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    distinct--;
                    mp.erase(nums[left]);
                }
                
                left++;
            }
            s+=right-left+1;
        }
        return s;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostkdistinct(nums,k)-atmostkdistinct(nums,k-1);
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int mx=0;
        int right;
        int cnt=0;
        for(right=0;right<nums.size();right++)
        {
            if(nums[right]==0)
                cnt++;
            while(cnt>1)
            {
                if(nums[left]==0)
                    cnt--;
                left++;
            }
            mx=max(mx,right-left);
        }
        return mx;
    }
};
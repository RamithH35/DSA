class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int left=0;
        int maxinc=1;
        int inc=1;
        int dec=1;
        for(int right=1;right<nums.size();right++)
        {
            if(nums[right]<=nums[right-1])
                left=right;
            inc=right-left+1;
            maxinc=max(inc,maxinc);
        }
        left=0;
        int maxdec=1;
        for(int right=1;right<nums.size();right++)
        {
            if(nums[right]>=nums[right-1])
                left=right;
            dec=right-left+1;
            maxdec=max(dec,maxdec);
        }
        return max(maxinc,maxdec);
    }
};
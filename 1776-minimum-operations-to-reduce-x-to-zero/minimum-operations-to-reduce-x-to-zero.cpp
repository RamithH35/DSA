class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0;
        int right;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<x)
            return -1;
        int s=sum-x;
        long long runsum=0;
        int mx=-1;
        for(right=0;right<nums.size();right++)
        {
            runsum+=nums[right];
            while(runsum>s)
            {
                runsum-=nums[left];
                left++;
            }
            if(runsum==s)
                mx=max(mx,right-left+1);
        }
        return (mx==-1)?-1:nums.size()-mx;

    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++)
        {
            if(i==0)
                left=0;
            else
                left+=nums[i-1];
            int right = sum-left-nums[i];
            if(left==right)
                return i;
        }
        return -1;
    }
};
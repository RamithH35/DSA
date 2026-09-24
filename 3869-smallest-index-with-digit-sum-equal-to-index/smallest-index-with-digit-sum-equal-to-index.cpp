class Solution {
public:
    int retsum(int x)
    {
        int y=0;
        while(x)
        {
            y+=x%10;
            x=x/10;
        }
        return y;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int x=retsum(nums[i]);
            if(x==i)
                return i;
        }
        return -1;
    }
};
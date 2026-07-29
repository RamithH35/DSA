class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
    /*
    lower bound first index where >= target
    binary search method 
    bsforlowerbound()
    {
        low=0,high=n-1;
        ans=n;
        while(low<=high)
        {
            mid=low+high/2;
            if(a[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }

    */
};
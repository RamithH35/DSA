class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int y=0;
        bool hasnonzero=false;
        for(int x:nums)
        {
            y=y^x;
            if(x!=0)
                hasnonzero=true; 
        }
        if(y!=0)
            return nums.size();
        else if(hasnonzero)
            return nums.size()-1;
        return 0;
    }
};
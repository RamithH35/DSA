class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        for(int x:nums)
        {
            sum+=x;
            mini=min(mini,x);
        }
        return sum-(n*mini);
    }
};
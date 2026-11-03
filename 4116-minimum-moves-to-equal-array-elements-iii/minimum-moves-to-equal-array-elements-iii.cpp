class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=INT_MIN;
        int sum=0;
        int n=nums.size();
        for(int x:nums)
        {
            mx=max(mx,x);
            sum+=x;
        }
        return n*mx-sum;
    }
};
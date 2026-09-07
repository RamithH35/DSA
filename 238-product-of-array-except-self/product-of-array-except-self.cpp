class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int prev=1;
        res[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            res[i]=res[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            int x = res[i];
            res[i]=x*prev;
            prev=prev*nums[i];
        }
        return res;
    }
};
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int mx=INT_MIN;
        int x=INT_MAX;
        vector<int>res;
        for(int i=nums.size()-1;i>=0;i--)
        {
            mini=min(mini,nums[i]);
            res.push_back(mini);
        }
        reverse(res.begin(),res.end());
        for(int j=0;j<nums.size();j++)
        {
            mx=max(mx,nums[j]);
            int s=mx-res[j];
            if(s<=k)
                x=min(x,j);
        }
        return x==INT_MAX?-1:x;
    }
};
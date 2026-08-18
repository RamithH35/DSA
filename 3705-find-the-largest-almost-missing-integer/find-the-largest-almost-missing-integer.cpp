class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(int x:nums) 
            freq[x]++;
        if(k==n)
            return *max_element(nums.begin(),nums.end());
        if(k==1)
        {
            int maxi=-1;
            for(int &x:nums)
            {
                if(freq[x]==1 && x>maxi)
                    maxi=x;
            }
            return maxi;
        }
        int ans=-1;
        if(freq[nums[0]]==1)
            ans=max(ans,nums[0]);
        if(freq[nums[n-1]]==1)
            ans=max(ans,nums[n-1]);
        return ans;
    }
};
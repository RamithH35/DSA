class Solution {
public:
    void helper(int ind,vector<int>&ds,vector<int>&nums,vector<vector<int>>&res)
    {
        res.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            helper(i+1,ds,nums,res);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>ds;
        helper(0,ds,nums,res);
        return res;
    }
};
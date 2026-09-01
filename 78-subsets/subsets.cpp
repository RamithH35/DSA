class Solution {
public:
    void generate(int i,vector<int>&ds,vector<vector<int>>&res,vector<int>&nums)
    {
        if(i==nums.size())
        {
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        generate(i+1,ds,res,nums);
        ds.pop_back();
        generate(i+1,ds,res,nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        generate(0,ds,res,nums);
        return res;
    }
};
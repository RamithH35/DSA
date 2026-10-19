class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int n=nums.size();
        if(nums.size()==0)
            return res;
        int st=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]+1)
            {
                if(st==i-1)
                    res.push_back(to_string(nums[st]));
                else
                    res.push_back(to_string(nums[st])+"->"+to_string(nums[i-1]));
                st=i;

            }
        }
        if(st==nums.size()-1)
            res.push_back(to_string(nums[st]));
        else
            res.push_back(to_string(nums[st])+"->"+to_string(nums[n-1]));
        return res;
    }
};
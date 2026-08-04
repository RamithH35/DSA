class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int cur=mini+1;
        vector<int>mis;
        while(cur<=maxi)
        {
            if(find(nums.begin(),nums.end(),cur)==nums.end())
                mis.push_back(cur);
            cur++;
        }
        return mis;
    }
};
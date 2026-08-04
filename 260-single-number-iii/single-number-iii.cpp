class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> v;

        for (int i = 0; i < nums.size(); i++) {
            if (find(v.begin(), v.end(), nums[i]) != v.end())
                v.erase(remove(v.begin(), v.end(), nums[i]), v.end());
            else
                v.push_back(nums[i]);
        }

        return v;
    }
};
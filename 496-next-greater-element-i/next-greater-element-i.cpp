class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        for (auto x : nums1) {
            int ind = mp[x];
            int ele = -1;
            for (int i = ind + 1; i < nums2.size(); i++) {
                if (nums2[i] > x) {
                    ele = nums2[i];
                    break;
                }
            }

            res.push_back(ele);
        }

        return res;
    }
};
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k / 2);

        vector<double> res;
        int n = nums.size();

        for (int i = k;; i++) {
            if (k % 2)
                res.push_back((double)*mid);
            else
                res.push_back(((double)*mid + (double)*prev(mid)) / 2.0);

            if (i == n) break;

            ms.insert(nums[i]);
            if (nums[i] < *mid) mid--;

            if (nums[i - k] <= *mid) mid++;
            ms.erase(ms.lower_bound(nums[i - k]));
        }

        return res;
    }
};
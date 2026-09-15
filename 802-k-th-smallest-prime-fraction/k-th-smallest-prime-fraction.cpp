class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>,
                       vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;

        int cnt = 0;
        int n = arr.size();
        int j = n - 1;
        for (int i = 0; i < n - 1; i++) {
            double val = (double)arr[i] / arr[j];
            pq.push({val, {i, j}});
        }

        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();

            cnt++;

            if (cnt == k)
                return {arr[c.second.first], arr[c.second.second]};

            int x = c.second.first;
            int y = c.second.second - 1;

            if (y > x) {
                double v = (double)arr[x] / arr[y];
                pq.push({v, {x, y}});
            }
        }

        return {};
    }
};
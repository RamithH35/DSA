class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        string res = "";
        int seat = 0;

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        for (auto& x : mp)
            pq.push({x.second, x.first});

        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();

            if (seat == 0 || res[seat - 1] != c.second) {
                res += c.second;
                seat++;

                c.first--;

                if (c.first > 0)
                    pq.push(c);
            } 
            else {
                if (pq.empty())
                    return "";

                auto d = pq.top();
                pq.pop();

                res += d.second;
                seat++;
                d.first--;

                if (c.first > 0)
                    pq.push(c);

                if (d.first > 0)
                    pq.push(d);
            }
        }

        return res;
    }
};
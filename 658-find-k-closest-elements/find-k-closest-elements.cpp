class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b)
        {
            if(a.first!=b.first)
                return b.first>a.first;
            return b.second>a.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        vector<int>res;
        for(auto &a:arr)
        {
            int diff = abs(a-x);
            if(pq.size()<k)
            {
                pq.push({diff,a});
                continue;
            }
            if(diff>pq.top().first || (diff==pq.top().first && a>pq.top().second))
                continue;
            pq.pop();
            pq.push({diff,a});
        }
        while(pq.size())
        {
            auto c = pq.top();
            pq.pop();
            res.push_back(c.second);
        }
        sort(res.begin(),res.end());
        return res;

    }
};
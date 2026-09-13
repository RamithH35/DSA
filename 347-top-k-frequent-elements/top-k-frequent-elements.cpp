class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>&a,const pair<int,int>&b)
        {
            if(a.second!=b.second)
                return b.second<a.second;
            return b.first<a.first;            
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int &x:nums)
            mp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(auto &y:mp)
        {
            if(pq.size()<k)
            {
                pq.push(y);
                continue;
            }
            if(pq.top().second>y.second)
                continue;
            pq.pop();
            pq.push(y);
        }
        while(pq.size())
        {
            auto c=pq.top();
            int x=c.first;
            res.push_back(x);
            pq.pop();
        }
        return res;
    }
};
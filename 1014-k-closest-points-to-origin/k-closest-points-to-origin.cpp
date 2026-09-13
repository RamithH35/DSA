class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b)
        {
                return b.first>a.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>pq;
        vector<vector<int>>res;
        for(auto &z:points)
        {
            int x=z[0];
            int y=z[1];
            int d=x*x+y*y;
            if(pq.size()<k)
            {
                pq.push({d,{x,y}});
                continue;
            }
            if(pq.top().first<d)
                continue;
            pq.pop();
            pq.push({d,{x,y}});
        }
        while(pq.size())
        {
            auto c=pq.top();
            res.push_back({c.second.first,c.second.second});
            pq.pop();
            
        }
        return res;
    }
};
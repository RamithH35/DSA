class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<pair<char,pair<int,int>>>q;
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        int t=0;
        for(auto &c:tasks)
            mp[c]++;
        for(auto &x:mp)
            pq.push({x.second,x.first});
        while(!pq.empty() || !q.empty())
        {
            while(!q.empty() && q.front().second.second<=t)
            {
                auto y=q.front();
                q.pop();
                pq.push({y.second.first,y.first});
            }
            if(!pq.empty())
            {
                auto x=pq.top();
                pq.pop();
                if(x.first-1>0)
                {
                    q.push({x.second,{x.first-1,t+n+1}});
                }
            }
            t++;
        }
        return t;
    }
};
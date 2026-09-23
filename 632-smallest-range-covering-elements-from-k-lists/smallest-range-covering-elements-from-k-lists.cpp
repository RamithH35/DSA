class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
        {
            if(a.first!=b.first)
                return b.first<a.first;
            return b.second.first<a.second.first;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>pq;
        vector<int>res;
        int diff=INT_MAX;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        while(!pq.empty())
        {
            mini=pq.top().first;
            auto c=pq.top();
            pq.pop();
            if(maxi-mini<diff)
            {
                diff=maxi-mini;
                res={mini,maxi};
            }
            int i=c.second.first;
            int j=c.second.second+1;
            if(c.second.second+1<nums[i].size())
            {
                maxi=max(maxi,nums[i][j]);
                pq.push({nums[i][j],{i,j}});
            }
            else
                break;
        }
        return res;
    }
};
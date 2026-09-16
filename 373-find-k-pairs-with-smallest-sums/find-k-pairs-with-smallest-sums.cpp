class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,pair<int,int>>&a,const pair<int,pair<int,int>>&b)
        {
            if(a.first!=b.first)
                return b.first<a.first;
            return b.second.first<a.second.first;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>pq;
        int n=0;
        vector<vector<int>>res;
        int y = min(k, (int)nums1.size());
        for(int i=0;i<y;i++)
        {
            int x=nums1[i]+nums2[0];
            pq.push({x,{i,0}});
        }
        while(n<k)
        {
            auto x=pq.top();
            int i=x.second.first;
            int j=x.second.second;
            pq.pop();
            res.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size())
            {
                int val=nums1[i]+nums2[j+1];
                pq.push({val,{i,j+1}});
            }
            n++;
        }
        return res;

    }
};
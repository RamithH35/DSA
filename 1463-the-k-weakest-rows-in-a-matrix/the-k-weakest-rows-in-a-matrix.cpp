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
    int countones(vector<int>&arr)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
                return i;
        }
        return arr.size();
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        vector<int>res;
        for(int i=0;i<mat.size();i++)
        {
            int num = countones(mat[i]);
            if(pq.size()<k)
            {
                pq.push({num,i});
                continue;
            }
            if(num>pq.top().first || (num==pq.top().first && i>pq.top().second))
                continue;
            pq.push({num,i});
            pq.pop();
        }
        while(pq.size())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
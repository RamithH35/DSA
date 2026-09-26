class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
            return arr;
        priority_queue<int,vector<int>,greater<int>>pq;
        int prev=0;
        for(auto x:arr)
            pq.push(x);
        unordered_map<int,int>mp;
        prev=pq.top();
        int rank=1;
        mp[prev]=1;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            if(x!=prev)
            {
                rank++;
                mp[x]=rank;
            }
            prev=x;
        }
        for(auto &x:arr)
        {
            x=mp[x];
        }
        return arr;

    }
};
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>res;
        priority_queue<int>pq;
        int i=0;
        int n=profits.size();
        while(i<n)
        {
            res.push_back({capital[i],profits[i]});
            i++;
        }
        i=0;
        sort(res.begin(),res.end());
        while(k>0)
        {
            while(i<n && res[i][0]<=w){
                pq.push(res[i][1]);
                i++;
            }
            if(pq.empty())
                return w;
            auto c=pq.top();
            pq.pop();
            w+=c;
            k--;
        }
        return w;

    }
};
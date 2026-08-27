class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>res;
        int n=position.size();
        stack<double>st;
        for(int i=0;i<n;i++)
            res.push_back({position[i],speed[i]});
        sort(res.begin(),res.end());
        for(int i=n-1;i>=0;i--)
        {
            double t=(double)(target-res[i].first)/res[i].second;
            if(st.empty()||t>st.top())
                st.push(t);
        }
        return st.size();

    }
};
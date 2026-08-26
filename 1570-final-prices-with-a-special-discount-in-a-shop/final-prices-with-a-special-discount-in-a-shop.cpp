class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res(prices.begin(),prices.end());
        int n=res.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&prices[st.top()]>prices[i])
                st.pop();
            if(!st.empty())
                res[i]=res[i]-prices[st.top()];
            st.push(i);
        }
        return res;
    }
};
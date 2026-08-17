class Solution {
public:
    vector<int> nse(vector<int>&a)
    {
        int s=a.size();
        vector<int>n(s);
        stack<int>st;
        for(int i=s-1;i>=0;i--)
        {
            while(!st.empty()&&a[st.top()]>=a[i])
                st.pop();
            n[i]=(st.empty())?s:st.top();
            st.push(i);
        }
        return n;
    }
    vector<int> pse(vector<int>&a)
    {
        int s=a.size();
        vector<int>n(s);
        stack<int>st;
        for(int i=0;i<s;i++)
        {
            while(!st.empty()&&a[st.top()]>a[i])
                st.pop();
            n[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return n;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>next=nse(arr);
        vector<int>prev=pse(arr);
        int mod=(1e9+7);
        int total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=i-prev[i];
            int right=next[i]-i;
            total = (total + (1LL*left*right*arr[i])%mod)%mod;
        }
        return total;
    }
};
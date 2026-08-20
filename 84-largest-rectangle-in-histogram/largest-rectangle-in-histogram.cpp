class Solution {
public:
    vector<int>pse(vector<int>&arr)
    {
        vector<int>res(arr.size());
        stack<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                res[i]=-1;
            else
                res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    vector<int>nse(vector<int>&arr)
    {
        vector<int>res(arr.size());
        stack<int>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
                res[i]=n;
            else
                res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=pse(heights);
        vector<int>next=nse(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int count=(next[i]-prev[i]-1)*heights[i];
            maxi = max(maxi,count);

        }
        return maxi;
    }
};
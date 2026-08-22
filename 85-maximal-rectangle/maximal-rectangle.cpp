class Solution {
public:
    int largestrectangle(vector<int>&ans)
    {
        int mx=0;
        stack<int>st;
        for(int i=0;i<=ans.size();i++)
        {
            while(!st.empty()&&(i==ans.size()||ans[st.top()]>ans[i]))
            {
                int ele=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                int right=i;
                int width=(right-left-1);
                mx=max(mx,ans[ele]*width);
            }
            if(i<ans.size())
                st.push(i);
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int res=0;
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<m;j++)
            {
                if(matrix[j][i]=='0')
                    sum=0;
                else
                    sum++;
                ans[j][i]=sum;
            }
        }
        for(int k=0;k<m;k++)
            res=max(res,largestrectangle(ans[k]));
        return res;
    }
};
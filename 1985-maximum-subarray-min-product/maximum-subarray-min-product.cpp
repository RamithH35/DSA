class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<long long>pre(n+1,0);
        long long mx=INT_MIN;
        for(int i=0;i<n;i++)
            pre[i+1]=pre[i]+nums[i];
        for(int i=0;i<=n;i++)
        {
            while(!st.empty()&&(i==n||nums[st.top()]>=nums[i]))
            {
                int ele=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();
                long long s=(pre[i]-pre[left+1]);
                mx=max(mx,nums[ele]*s);
            }
            if(i<n)
                st.push(i);
        }
        return mx%1000000007;

        
    
        
    }
};
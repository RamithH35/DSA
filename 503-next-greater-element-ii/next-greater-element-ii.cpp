class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        vector<int>nge(nums.size());
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i])
                st.pop();
            if(st.empty()) nge[i]=-1;
            else
                nge[i]=st.top();
            st.push(nums[i]);
        }
        vector<int>res(nge.begin(),nge.begin()+n);
        return res;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int &x:nums)
            st.insert(x);
        int mul=k;
        while(st.find(mul)!=st.end())
            mul=mul+k;
        return mul;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char c:s)
        {
            if(st.empty() || st.top().first!=c)
                st.push({c,1});
            else
            {
                int cnt=st.top().second+1;
                if(cnt==k)
                    st.pop();
                else
                {
                    st.top().second=cnt;
                }
            }
            
        }
        string ans="";
        while(!st.empty())
        {
            ans.append(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int calPoints(vector<string>& op) {
        stack<int>st;
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=="D")
            {
                int x=st.top();
                st.push(2*x);
            }
            else if(op[i]=="C")
                st.pop();
            else if(op[i]=="+")
            {
                int x = st.top();
                st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }
            else
                st.push(stoi(op[i]));
        }
        int s=0;
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        return s;
    }
};
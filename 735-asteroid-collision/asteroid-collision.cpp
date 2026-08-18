class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int x:asteroids)
        {
            
            if(st.empty()||st.top()<0||x>0)
                st.push(x);
            else
            {
                bool survive=true;
                while(!st.empty() && st.top()>0 && x<0)
                {
                    if(abs(st.top())>abs(x))
                    {
                        survive=false;
                        break;
                    }
                    else if(abs(st.top())==abs(x))
                    {
                        survive=false;
                        st.pop();
                        break;
                    }
                    else
                        st.pop();
                }
                if(survive)
                    st.push(x);
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
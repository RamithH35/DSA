class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0; i<tokens.size(); i++){
            string c = tokens[i];
            
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                int ans = 0;

                if(c == "+") ans = first + second;
                else if(c == "-") ans = second - first;
                else if(c == "*") ans = first * second;
                else ans = second/first;

                st.push(ans);

            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};
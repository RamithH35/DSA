class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }
        while (k > 0) {
            st.pop_back();
            k--;
        }
        int pos = st.find_first_not_of('0');
        if (pos == string::npos)
            return "0";

        return st.substr(pos);
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            }
            else if (s[i] == ')') {
                if (!stack.empty()) {
                    stack.pop_back();
                }
                else {
                    s[i] = '*';
                }
            }
        }
        while (!stack.empty()) {
            s[stack.back()] = '*';
            stack.pop_back();
        }
        string result;
        for (char ch : s) {
            if (ch != '*') {
                result += ch;
            }
        }
        return result;
    }
};
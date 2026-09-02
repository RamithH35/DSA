class Solution {
public:
    void generate(string& s, int ind, string& digits, vector<string>& fn,
                  vector<string>& res) {

        if (ind == digits.size()) {
            res.push_back(s);
            return;
        }

        int x = digits[ind] - '0';

        for (int i = 0; i < fn[x].size(); i++) {
            s.push_back(fn[x][i]);

            generate(s, ind + 1, digits, fn, res);

            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> fn = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        string s;

        generate(s, 0, digits, fn, res);

        return res;
    }
};
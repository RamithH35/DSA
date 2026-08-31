class Solution {
public:
    void generate(string r, int n, vector<string>& res)
    {
        if(r.size() == n)
        {
            res.push_back(r);
            return;
        }

        if(r.back() == '1')
        {
            generate(r + "1", n, res);
            generate(r + "0", n, res);
        }
        else
        {
            generate(r + "1", n, res);
        }
    }

    vector<string> validStrings(int n)
    {
        vector<string> res;

        generate("1", n, res);
        generate("0", n, res);

        return res;
    }
};
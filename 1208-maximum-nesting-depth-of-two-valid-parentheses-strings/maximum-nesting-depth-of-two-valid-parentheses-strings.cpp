class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>res;
        int level=0;
        for(char c:seq)
        {
            if(c=='(')
            {
                level++;
                res.push_back(level%2);

            }
            else
            {
                res.push_back(level%2);
                level++;
            }
        }
        return res;
    }
};
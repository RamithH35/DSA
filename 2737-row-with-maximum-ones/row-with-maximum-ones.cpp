class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=-1,cnt=-1;
        for(int i=0;i<mat.size();i++)
        {
            int c=0;
            for(int x :mat[i])
                if(x==1)
                    c++;
            if(c>cnt)
            {
                cnt=c;
                row=i;
            }
        }
        return {row,cnt};
    }
};
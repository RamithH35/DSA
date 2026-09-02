class Solution {
public:
    void generate(int k,int s,int c,vector<int>&ds,vector<vector<int>>&res)
    {
        if(k==0)
        {
            if(s==0)
                res.push_back(ds);
            return;
        }
        if(s<0)
            return;
        for(int i=c;i<=9;i++)
        {
            ds.push_back(i);
            generate(k-1,s-i,i+1,ds,res);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>res;
        generate(k,n,1,ds,res);
        return res;
    }
};
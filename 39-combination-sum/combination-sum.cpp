class Solution {
public:
    void calculate(int i,int target,vector<int>&ds,int n,vector<int>&c,vector<vector<int>>&res)
    {
        if(target==0)
        {
            res.push_back(ds);
            return;
        }
        if(target<0 || i==n)
            return;
        ds.push_back(c[i]);
        calculate(i,target-c[i],ds,n,c,res);
        ds.pop_back();
        calculate(i+1,target,ds,n,c,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        int n = candidates.size();
        calculate(0,target,ds,n,candidates,res);
        return res;

    }
};
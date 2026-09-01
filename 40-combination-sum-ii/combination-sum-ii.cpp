class Solution {
public:
    void generate(int index,int target,vector<int>&ds,vector<int>c,vector<vector<int>>&res)
    {
        if(target==0)
        {
            res.push_back(ds);
            return;
        }
        for(int i=index;i<c.size();i++)
        {
            if(i>index && c[i]==c[i-1])continue;
            if(c[i]>target) break;
            ds.push_back(c[i]);
            generate(i+1,target-c[i],ds,c,res);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>ds;
        generate(0,target,ds,candidates,res);
        return res;
    }
};
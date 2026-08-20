class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>res(nums.size());
        int n=nums.size();
        int a1=0,a2=n-1;
        res[a1]=nums[0];
        res[a2]=nums[1];
        for(int i=2;i<n;i++)
        {
            if(res[a1]>res[a2])
                res[++a1]=nums[i];
            else
                res[--a2]=nums[i];
        }
        reverse(res.begin()+a1+1,res.end());
        return res;
    }
};
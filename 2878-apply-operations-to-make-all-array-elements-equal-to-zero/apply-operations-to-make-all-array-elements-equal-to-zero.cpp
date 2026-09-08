class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dif(n+1,0);
        int effect=0;
        for(int i=0;i<n;i++)
        {
            effect+=dif[i];
            int cur=nums[i]+effect;
            if(cur<0)
                return false;
            if(cur==0)
                continue;
            if(i+k>n)
                return false;
            int x=cur;
            effect-=x;
            dif[i+k]+=x;
        }
        return true;
    }
};
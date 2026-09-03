class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int e=0;
        int o=0;
        int n=nums1.size();
        int minodd=INT_MAX;
        for(auto &x:nums1)
        {
            if(x%2==0)
                e++;
            else
            {
                o++;
                minodd=min(x,minodd);
            }
        }
        if(e==n || o==n)
            return true;
        for(auto &y:nums1)
        {
            if(y%2==0 && y<minodd)
                return false;
        }
        return true;
    }
};
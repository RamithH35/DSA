class Solution {
public:
    int trap(vector<int>& height) {
        int total=0,n=height.size();
        int lmax=-1;
        vector<int>suffmax(n);
        suffmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            suffmax[i]=max(suffmax[i+1],height[i]);
        for(int i=0;i<n;i++)
        {
            lmax=max(lmax,height[i]);
            if(height[i]<lmax && height[i]<suffmax[i])
            {
                total+=min(lmax,suffmax[i])-height[i];
            }
        }
        return total;
    }
};
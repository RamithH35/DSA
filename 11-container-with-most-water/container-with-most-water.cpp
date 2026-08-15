class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int mxarea=INT_MIN;
        while(i<j)
        {
            int area=(j-i)*min(height[j],height[i]);
            mxarea=max(area,mxarea);
            if(height[j]<height[i])
                j--;
            else 
                i++;
        }
        return mxarea;
    }
};
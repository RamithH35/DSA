class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int nearx=max(x1,min(x2,xc));
        int neary=max(y1,min(y2,yc));
        int ans1=xc-nearx;
        int ans2=yc-neary;
        return ans1*ans1 + ans2*ans2 <=r*r;
    }
};
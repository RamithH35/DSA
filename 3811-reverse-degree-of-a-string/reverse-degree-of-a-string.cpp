class Solution {
public:
    int reverseDegree(string s) {
        int x=0;
        int y=1;
        for(char &c:s)
        {
            int v = 'z'-c+1;
            x += v*y;
            y++;
        }
        return x;
    }
};
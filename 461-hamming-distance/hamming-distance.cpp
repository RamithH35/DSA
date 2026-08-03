class Solution {
public:
    int hammingDistance(int x, int y) {
        long a=x^y;
        long cnt=0;
        while(a>0)
        {
            if(a&1)
                cnt++;
            a>>=1;
        }
        return cnt;
    }
};
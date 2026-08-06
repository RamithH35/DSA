class Solution {
public:
    int proddigits(int x)
    {
        int prod=1;
        while(x)
        {
            int r=x%10;
            prod=prod*r;
            x=x/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int y=n;
        while(true)
        {
            if(proddigits(y)%t==0)
                return y;
            y++;
        }
        return -1;
    }
};
class Solution {
public:
    int maxProduct(int n) {
        int fmax=INT_MIN;
        int smax=INT_MIN;
        while(n)
        {
            int x = n%10;
            if(x>fmax)
            {
                smax=fmax;
                fmax=x;
            }
            else if(x>smax)
                smax=x;
            n=n/10;
        }
        return fmax*smax;
        
    }
};
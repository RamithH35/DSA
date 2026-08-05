class Solution {
public:
    double myPow(double x, int n) {
    long long exp=abs((long long)n);
    double ans=1.0;
    bool negative=n<0;
    while(exp)
    {
        if(exp%2)
        {
            ans=ans*x;
            exp=exp-1;
        }
        else
        {
            x=x*x;
            exp/=2;
        }
    }
    if(negative)
        ans= (double)1.0/(double)ans;
    return ans;
    }   
};
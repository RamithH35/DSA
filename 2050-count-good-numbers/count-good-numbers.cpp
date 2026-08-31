class Solution {
public:
    long long Mod = 1e9+7;
    long long power(long long x,long long n)
    {
        long long res=1;
        long long y=n;
        while(y)
        {
            if(y%2!=0)
                res = (res*x)%Mod;
            x=(x*x)%Mod;
            y/=2;
            
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long even_pow=(n+1)/2;
        long long odd_pow=n/2;
        long long x = (power(5,even_pow))%Mod;
        long long y = (power(4,odd_pow))%Mod;
        return (x*y)%Mod;
    }
};
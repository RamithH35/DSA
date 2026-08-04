class Solution {
public:
    bool checkPerfectNumber(int n) {
        if(n==1) return false;
        int res=1;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                res+=i;
                if(n/i!=i)
                    res+=n/i;
            }
        }
        return (res==n);
    }
};
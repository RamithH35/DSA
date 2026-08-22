class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0;
        int p=1;
        int y=n;
        while(n)
        {
            int x = n%10;
            s+=x;
            p*=x;
            n/=10;
        }
        return ((y%(s+p))==0);
    }
};
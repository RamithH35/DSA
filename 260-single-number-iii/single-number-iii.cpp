class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long n=0;
        for(int i:nums)
            n=n^i;
        long m=(n&(n-1));
        n=n^m;
        int one=0;
        int zero=0;
        for(int x:nums)
        {
            if(x&n)
                one=one^x;
            else 
                zero=zero^x;
        }
        return{one,zero};
    }
};
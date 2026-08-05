class Solution {
public:
    int countPrimes(int n) {
    if(n<=2) return 0;
    vector<int>arr(n,1);
    int cnt=0;
    for(int i=2;i*i<n;i++)
    {
        if(arr[i]==1)
        {
            for(int j=i*i;j<n;j+=i)
                arr[j]=0;
        }
    }
    for(int k=2;k<n;k++)
    {
        if(arr[k])
            cnt++;
    }
    return cnt;
    }
};
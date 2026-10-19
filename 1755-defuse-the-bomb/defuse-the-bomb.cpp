class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0)
        {
            for(int &x:code)
                x=0;
            return code;
        }
        if(k>0)
        {
            int n=code.size();
            vector<int>res(n,0);
            int sum=0;
            for(int i=1;i<=k;i++)
            {
                sum+=code[i%n];
            }
            res[0]=sum;
            for(int j=1;j<n;j++)
            {
                sum-=code[j];
                sum+=code[(j+k)%n];
                res[j]=sum;
            }
            return res;

        }
        else
        {
            int n=code.size();
            int m=abs(k);
            vector<int>res(n,0);
            int sum=0;
            for(int i=1;i<=abs(k);i++)
            {
                sum+=code[(n-i)%n];
            }
            res[0]=sum;
            for(int i=1;i<n;i++)
            {
                sum-=code[(i-m-1+n)%n];
                sum+=code[i-1];
                res[i]=sum;
            }
            return res;
        }
        return {};
    }
};
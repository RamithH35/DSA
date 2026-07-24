class Solution {
public:
    int check(vector<int>&arr,long long page)
    {
        int cnt=1,cur=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(cur+arr[i]<=page)
                cur+=arr[i];
            else
            {
                cnt++;
                cur=arr[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& arr, int k) {
        int low=*max_element(arr.begin(),arr.end());
        long long high=accumulate(arr.begin(),arr.end(),0LL);
        while(low<=high)
        {
            long long mid=(low)+(high-low)/2;
            int x=check(arr,mid);
            if(x>k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};
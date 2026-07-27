class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int low=0,high=a.size()-1;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(a[mid]>a[mid+1])
                high=mid;
            else 
                low=mid+1;

        }
        return low;
    }
};
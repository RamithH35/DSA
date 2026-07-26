class Solution {
public:
    bool search1(vector<int>matrix,int target)
    {
        int l=0,h=matrix.size()-1;
        while(l<=h)
        {
            int m=(l)+(h-l)/2;
            if(matrix[m]==target)
                return true;
            else if(matrix[m]>target)
                h=m-1;
            else
                l=m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1;
        int n=matrix[0].size();
        while(low<=high)
        {
            int mid=(low)+(high-low)/2;
            if(target<matrix[mid][0])
                high=mid-1;
            else if(target>matrix[mid][n-1])
                low=mid+1;
            else
                return search1(matrix[mid],target);
        }
        return false;
    }
};
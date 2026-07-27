class Solution {
public:
    bool search(vector<int>&v,int target)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(target>=matrix[i][0] && target <=matrix[i][m-1])
            {
                bool x = search(matrix[i],target);
                if(x==true)
                    return x;
            }
        }
        return false;
    }
};
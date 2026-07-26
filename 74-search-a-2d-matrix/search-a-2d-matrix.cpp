class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n*m-1;
        while(low<=high)
        {
            int mid=(low)+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            int el=matrix[row][col];
            if(el == target) return true;
            else if(el<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};
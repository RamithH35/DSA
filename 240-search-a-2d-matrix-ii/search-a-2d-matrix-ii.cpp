class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0)
        {
            int el=matrix[row][col];
            if (el==target)
                return true;
            else if(el<target)
                row++;
            else
                col--;
        }
        return false;
    }
};
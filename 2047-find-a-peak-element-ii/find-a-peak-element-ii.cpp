class Solution {
public:
    int findmax(vector<vector<int>>&mat,int n ,int m , int col)
    {
        int maxo=INT_MIN,index=-1;
        for(int i=0;i<n;i++)
        {
            if(mat[i][col]>maxo)
            {
                maxo=mat[i][col];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int maxindex=findmax(mat,n,m,mid);
            int left = mid-1>=0 ? mat[maxindex][mid-1]:-1;
            int right = mid+1<m ? mat[maxindex][mid+1]:-1;
            int el=mat[maxindex][mid];
            if(el>left && el>right)
                return {maxindex,mid};
            else if(el<left)
                high=mid-1;
            else 
                low=mid+1;
        }
        return {-1,-1};
    }
};
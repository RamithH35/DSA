class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int minutes=0;
        int fresh=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)   
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty() && fresh>0)
        {
            int sz=q.size();
            while(sz)
            {
                int row=q.front().first;
                int col=q.front().second;
                if(row-1>=0 && grid[row-1][col]==1)
                {
                    q.push({row-1,col});
                    grid[row-1][col]=2;
                    fresh--;
                }
                
                if(row+1<m && grid[row+1][col]==1){
                    q.push({row+1,col});
                    grid[row+1][col]=2;
                    fresh--;
                }
                if(col-1>=0 && grid[row][col-1]==1){
                    q.push({row,col-1});
                    grid[row][col-1]=2;
                    fresh--;
                }
                    
                if(col+1<n && grid[row][col+1]==1){
                    q.push({row,col+1});
                    grid[row][col+1]=2;
                    fresh--;
                }
                q.pop();
                --sz;
            }
            minutes++;
        }
        return fresh==0?minutes:-1;
    }
};
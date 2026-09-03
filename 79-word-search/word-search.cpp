class Solution {
public:
    bool check(int row,int col,int index,int m,int n,string &word,vector<vector<int>>&res,vector<vector<char>>&board)
    {
        if(index==word.size())
            return true;
        if(row<0 || row >=m)
            return false;
        if(col<0 || col>=n)
            return false;
        if(res[row][col] || board[row][col]!=word[index])
            return false;
        res[row][col]=1;
        bool flag1 = (check(row,col+1,index+1,m,n,word,res,board) || check(row,col-1,index+1,m,n,word,res,board));
        bool flag2 = (check(row+1,col,index+1,m,n,word,res,board) || check(row-1,col,index+1,m,n,word,res,board));
        if(flag1 || flag2)
            return true;
        res[row][col]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>res(m,vector<int>(n,0));
        bool flag;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                flag=check(i,j,0,m,n,word,res,board);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};
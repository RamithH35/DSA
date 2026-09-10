class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int count=0;
        int n=matrix.size();
        for(int i=0;i<matrix.size();i++)
            pq.push({matrix[i][0],{i,0}});
        while(count!=k)
        {
            auto cur=pq.top();
            pq.pop();
            int val=cur.first;
            int row=cur.second.first;
            int col=cur.second.second;
            count++;
            if(count==k)
                return val;
            if(col+1<n)
            {
                pq.push({matrix[row][col+1],{row,col+1}});
            }
        }
        return -1;
    }
};
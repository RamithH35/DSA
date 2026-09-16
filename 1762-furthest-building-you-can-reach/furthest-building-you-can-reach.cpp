class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int c=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(c<n-1)
        {
            int diff=heights[c+1]-heights[c];
            if(diff<=0)
            {
                c++;
                continue;
            }
            else
            {
                pq.push(diff);
                if(pq.size()>ladders)
                {
                    int x=pq.top();
                    pq.pop();
                    bricks-=x;
                    if(bricks<0)
                        return c;
                }
                c++;
            }
        }
        return c;
    }
};
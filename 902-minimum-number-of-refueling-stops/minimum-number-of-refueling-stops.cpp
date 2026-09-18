class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int travel=0;
        int fuel=startFuel;
        int n=stations.size();
        priority_queue<int>pq;
        int stops=0;
        int i=0;
        while(travel<target)
        {
            travel+=fuel;
            if(travel>=target)
                break;
            fuel=0;
            while(i<n && stations[i][0]<=travel)
            {
                int x=stations[i][1];
                pq.push(x);
                i++;
            }
            if(pq.empty())
                return -1;
            fuel+=pq.top();
            pq.pop();
            stops++;

        }
        return stops;
    }
};
class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long sum=0;
        priority_queue<double>pq;
        for(int x:nums)
        {
            pq.push(x);
            sum+=x;
        }
        double target = sum/2.0;
        double reduce=0;
        int operations=0;
        while(reduce<target && !pq.empty())
        {
            double x=pq.top();
            pq.pop();
            x=x/2;
            reduce+=x;
            pq.push(x);
            operations++;
        }
        return operations;
    }
};
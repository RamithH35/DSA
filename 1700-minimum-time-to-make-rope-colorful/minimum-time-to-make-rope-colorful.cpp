class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int grptime=neededTime[0];
        int grpmax=neededTime[0];
        int count=0;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]!=colors[i-1])
            {
                count+=grptime-grpmax;
                grptime=neededTime[i];
                grpmax=neededTime[i];
            }
            else
            {
                grptime+=neededTime[i];
                grpmax=max(grpmax,neededTime[i]);
            }
        }
        count+=grptime-grpmax;
        return count;
    }
};
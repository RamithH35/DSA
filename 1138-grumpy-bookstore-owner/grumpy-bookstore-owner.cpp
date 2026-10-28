class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if(minutes>=grumpy.size())
            return accumulate(customers.begin(),customers.end(),0);
        int satisfied=0;
        int mx=0;
        int dis=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==0)
                satisfied+=customers[i];
            else
                dis+=customers[i];
        }
        mx=max(mx,dis);
        int k=0;
        for(int j=minutes;j<grumpy.size();j++)
        {
            if(grumpy[j]==0)
                satisfied+=customers[j];
            else
                dis+=customers[j];

            if(grumpy[k]==1)
                dis-=customers[k];
            k++;
            mx=max(mx,dis);
        }
        return satisfied+mx;
    }
};